#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>

int			sockfd, connfd, max_fd;
struct		sockaddr_in servaddr, cli;
fd_set		_fds, _fds_read, _fds_write;
socklen_t	len;
int			client = 0;
int			_usr[65000];
char *		_msg[65000];
char		buff[1025];
char		send_info[50];

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

void	send_all(int tmp, char *str)
{
	for (int fd = 0; fd <= max_fd; fd++)
	{
		if (FD_ISSET(fd, &_fds_write) && fd != tmp)
			send(fd, str, strlen(str), 0);
	}
}

void	fatal(void)
{
	write(2, "Fatal error\n", strlen("Fatal error\n"));
	exit(1);
}


int main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(2, "Wrong number of arguments\n", strlen("Wrong number of arugments\n"));
		exit(1);
	}
	// socket create and verification 
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) 
		fatal();
	bzero(&servaddr, sizeof(servaddr)); 

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(argv[1])); //port
  
	// Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
		fatal();
	if (listen(sockfd, 10) != 0)
		fatal(); 
	FD_ZERO(&_fds); // met fds a 0
	FD_SET(sockfd, &_fds); //ajoute un descripteur de ficher dans fds
	max_fd = sockfd;
	for (;;)
	{
		_fds_read = _fds_write = _fds;
	
		if (select(max_fd + 1, &_fds_read, &_fds_write, 0, 0) < 0)
			fatal();
		for (int fd = 0; fd <= max_fd; fd++)
		{
			if (!FD_ISSET(fd, &_fds_read)) //  FD_ISSET() vérifie si un descripteur est contenu dans un ensemble
				continue;
			if (fd == sockfd) // si nouveau client
			{
				len = sizeof(cli);
				if ((connfd = accept(sockfd, (struct sockaddr *)&cli, &len)) < 0) // extrait de la file des connexions en attente de la socket sockfd à l'écoute, crée une nouvelle socket connectée
					fatal();
				if (max_fd < connfd)
					max_fd = connfd;
				_usr[connfd] = client;
				client++;
				_msg[connfd] = NULL;
				sprintf(send_info, "server: client %d just arrived\n", _usr[connfd]);
				send_all(connfd, send_info); // envoie a tout les autres clients
				FD_SET(connfd, &_fds); //ajoute un descripteur de ficher dans fds
				break;
			}
			else
			{
				int ret = recv(fd, buff, 1024, 0); // renvoie la longueur du message si elle réussie
				if (ret <= 0)
				{
					sprintf(send_info, "server: client %d just left\n", _usr[fd]);
					send_all(fd, send_info);
					close(fd);
					free(_msg[fd]);
					_msg[fd] = NULL;
					FD_CLR(fd, &_fds); // supprime le fd de fds
					break;
				}
				buff[ret] = '\0';
				_msg[fd] = str_join(_msg[fd], buff);
				for (char *msg = NULL; extract_message(&_msg[fd], &msg);)
				{
					sprintf(send_info, "client %d: ", _usr[fd]);
					send_all(fd, send_info);
					send_all(fd, msg);
					free(msg);
					msg = NULL;
				}
			}
		}
	}
	return (0);
}