#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>

int sockfd, connfd, max_fd;
struct sockaddr_in servaddr, cli;
fd_set _fds, fd_read, fd_write;
socklen_t len;
int client = 0;
int _usr[65000];
char *_msg[65000];
char buff[1025];
char send_info[50];


int extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int	i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

char *str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

void send_all(int tmp, char *str)
{
    for (int fd = 4; fd <= max_fd; fd++)
        if (FD_ISSET(fd, &fd_write) && fd != tmp)
            send(fd, str, strlen(str), 0);
}

void fatal()
{
    write(2, "Fatal error\n", strlen("Fatal error\n"));
    exit(1);
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        write(2, "Wrong number of arguments\n", strlen("Wrong number of arguments\n"));
        exit(1);
    }

	// socket create and verification 
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        fatal();
	bzero(&servaddr, sizeof(servaddr)); 

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(av[1])); 
  
	// Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
        fatal();
	if (listen(sockfd, 10) != 0)
        fatal();
    FD_ZERO(&_fds); // set the _fds to 0
    FD_SET(sockfd, &_fds); // add a descriptor file in _fds
    max_fd = sockfd;

    for (;;)
    {
        fd_read = fd_write = _fds;
        if (select(max_fd + 1, &fd_read, &fd_write, 0, 0) < 0)
            fatal();
        for (int fd = 0; fd <= max_fd; fd++)
        {
            if (!FD_ISSET(fd, &fd_read)) // check if a descriptor file is contained in a set 
                continue;
            if (fd == sockfd) // if new client connect
            {
                len = sizeof(cli);
                if ((connfd = accept(sockfd, (struct sockaddr *)&cli, &len)) < 0 ) // extract from the queue of pending connections of the listening sockfd socket, create a new connected socket
                    fatal();
                if (max_fd < connfd)
                    max_fd = connfd;
                _usr[connfd] = client;
                client++;
                _msg[connfd] = NULL;
                sprintf(send_info, "server: client %d just arrived\n", _usr[connfd]);
                send_all(connfd, send_info); // send to all other clients that a new client arrived
                FD_SET(connfd, &_fds); // add a descriptor file in _fds
                break;
            }
            else
            {
                int ret = recv(fd, buff, 1024, 0); // return the length of the message if she success
                if (ret <= 0)
                {
                    sprintf(send_info, "server: client %d just left\n", _usr[fd]);
                    send_all(fd, send_info);
                    close(fd);
                    free(_msg[fd]);
                    _msg[fd] = NULL;
                    FD_CLR(fd, &_fds); // remove the fd from _fds
                    break;
                }
                buff[ret] = '\0';
                _msg[fd] = str_join(_msg[fd], buff);
                for (char *msg = NULL; extract_message(&_msg[fd], &msg);)
                {
                    sprintf(send_info, "client %d: ", _usr[fd]);
                    send_all(fd, send_info);
                    send_all(fd, msg); // send the messqge we receive from the client
                    free(msg);
                    msg = NULL;
                }
            }
        }
    }
    return (0);
}
