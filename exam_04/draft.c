
///////LIB
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <string.h>

//////STRUCT

typedef enum e_type
{
	SEP,
	PIPE,
	END,
}	t_type;

typedef struct s_cmd
{
	char	**av;
	char	**env;
	int	pipe_fd[2];
	t_type	type;
	t_type	prev_cmd_t;
	int	prev_cmd_p;
	
}		t_cmd;

/////FT_UTILS

int	ft_strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s)
{
	int fd = 2;	//STDERROR
	write(fd, s, ft_strlen(s));
}

int	ft_error(char *s1, char *s2)
{
	int fd = 2;	//STDERROR
	write(fd, "error: ", 7);
	if (s1)
		ft_putstr_fd(s1);
	if (s2)
		ft_putstr_fd(s2);
	write(fd, "\n", 1);
	return (1);	//case of error return 1
}

/////CD

int	ft_cd(t_cmd *cmd)
{
	int	i = 0;
	while(cmd->av[i])
		i++;
	if (i != 3)
		return (ft_error("cd: bad arguments", NULL));
	if (chdir(cmd->av[1]) == -1)
		return (ft_error("cd: cannot change directory to ", cmd->av[1]));
	return (0);
}

/////EXEC

int	ft_exec(t_cmd *cmd)
{
	pid_t	pid;
	printf("here\n");
	if (cmd->type == PIPE)
	{
		if (pipe(cmd->pipe_fd) == -1)
			return(ft_error("fatal", NULL));
	}
	pid = fork();
	if (pid < 0)
		return (ft_error("fatal", NULL));
	if (pid == 0)	// child
	{
		if (cmd->prev_cmd_t == PIPE)
			dup2(cmd->prev_cmd_p, 0);
		if (cmd->type == PIPE)
			dup2(cmd->pipe_fd[1], 1);
		printf("here before execve\n");
		if (execve(cmd->av[0], cmd->av, cmd->env) == -1)
		{
			ft_error("canoot execute", cmd->av[0]);
			exit(1);
		}
		printf("here after execve\n");
	}
	else
	{
		waitpid(pid, 0, 0);
		if (cmd->prev_cmd_t == PIPE)
			close (cmd->prev_cmd_p);
		if (cmd->type == PIPE)
			close(cmd->pipe_fd[1]);
		if (cmd->prev_cmd_t == PIPE && cmd->type != PIPE)
			close(cmd->pipe_fd[0]);
	}
	return (0);
}

/////PARSING


int	cmd_end(t_cmd *cmd, char **argv)
{
	int	i = 0;
	while (argv[i])
	{
		if (strcmp(argv[i], "|") == 0)
		{
			cmd->type = PIPE;
			argv[i] = NULL;
			return (i);
		}
		if (strcmp(argv[i], ";") == 0)
		{
			cmd->type = SEP;
			argv[i] = NULL;
			return (i);
		}
		i++;
	}
	cmd->type = END;
	return (1);
}

int	parsing_cmd(t_cmd *cmd, char **argv)
{
	int len;

	cmd->prev_cmd_t = cmd->type;
	cmd->prev_cmd_p = cmd->pipe_fd[0];
	cmd->av = argv;
	len = cmd_end(cmd, argv);
	return (len);
}

int main (int argc, char **argv, char **env)
{
	int	res;
	int	avance;
	int	i;
	t_cmd	cmd;

	cmd.pipe_fd[0] = 0;
	cmd.pipe_fd[1] = 1;
	cmd.env = env;
	cmd.type = END;
	res = 0;
	i = 1;
	while (i < argc && argv[i])
	{	
		avance = parsing_cmd(&cmd, argv);
		if (avance != 0)
		{
			if (strcmp(argv[i], "cd") == 0)
				res = ft_cd(&cmd);
			else
				res = ft_exec(&cmd);
		}
		i += avance + 1;
	}
	return (res);
}
