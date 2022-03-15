
///////LIB

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>


///////STRUCT

typedef enum e_type
{
	PIPE,
	SEP,
	END,
}	t_type;

typedef struct s_cmd
{
	char	**env;
	char	**av;
	int	pipe_fd[2];
	t_type	type;
	t_type	prev_cmd_t;
	int	prev_cmd_p;
}		t_cmd;


///////FT_UTILS

int	ft_strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

void	ft_putstr(char *s)
{
	int fd = 2;	//STDERR
	write (fd, s, ft_strlen(s));
}

int	ft_error(char *s1, char *s2)
{
	int fd = 2;	//STDERR
	write (fd, "error: ", 7);
	if (s1)
		ft_putstr(s1);
	if (s2)
		ft_putstr(s2);
	write (fd, "\n", 1);
	return (1);	//return (1) en cas d'erreur
}


///////CD

int	ft_cd(t_cmd *cmd)
{
	int i = 0;
	while(cmd->av[i])
		i++;
	if (i != 2)
		return (ft_error("cd: bad arguments", NULL));
	if (chdir(cmd->av[1]) == -1)
		return (ft_error("cd: cannot change directory path to ", cmd->av[1]));
	return (0);
}


///////EXEC

int	ft_exec(t_cmd *cmd)
{
	pid_t	pid;

	if (cmd->type == PIPE)
	{
		if (pipe(cmd->pipe_fd) == -1)
			return (ft_error("fatal", NULL));
	}
	pid = fork();
	if (pid < 0)
		return (ft_error("fatal", NULL));
	if (pid == 0)	//child
	{
		if (cmd->prev_cmd_t == PIPE)
		{
			if (dup2(cmd->prev_cmd_p, 0) < 0)
				return (ft_error("fatal", NULL));
		}
		if (cmd->type == PIPE)
		{
			if (dup2(cmd->pipe_fd[1], 1) < 0)
				return (ft_error("fatal", NULL));
		}
		if (execve(cmd->av[0], cmd->av, cmd->env) < 0)
		{
			ft_error("canot execute ", cmd->av[0]);
			exit(1);
		}
	}
	else
	{
		waitpid(pid, 0, 0);
		if (cmd->prev_cmd_t == PIPE)
			close(cmd->prev_cmd_p);
		if (cmd->type == PIPE)
			close(cmd->pipe_fd[1]);
		if (cmd->prev_cmd_t == PIPE && cmd->type == END)
			close(cmd->pipe_fd[0]);
	}
	return (0);
}


///////PARSING

int	cmd_end(t_cmd *cmd, char **argv)
{
	int	i = 0;

	while(argv[i])
	{
		if (strcmp(argv[i], "|") == 0)
		{
			argv[i] = NULL;
			cmd->type = PIPE;
			return (i);
		}
		if (strcmp(argv[i], ";") == 0)
		{
			argv[i] = NULL;
			cmd->type = SEP;
			return (i);
		}
		i++;
	}
	cmd->type = END;
	return (i);
}

int	parse_cmd(t_cmd *cmd, char **argv)
{
	int len;
	cmd->av = argv;
	cmd->prev_cmd_t = cmd->type;
	cmd->prev_cmd_p = cmd->pipe_fd[0];
	len = cmd_end(cmd, argv);
	return (len);
}


///////MAIN

int	main(int argc, char **argv, char **env)
{
	int	res;
	int	avance;
	int	i; 
	t_cmd	cmd;

	res = 0;
	cmd.pipe_fd[0] = 0;
	cmd.pipe_fd[1] = 1;
	cmd.env = env;
	cmd.type = END;
	i = 1;
	while(i < argc && argv[i])
	{
		avance = parse_cmd(&cmd, &argv[i]);
		if (avance != 0)
		{
			if (strcmp(argv[i], "cd") == 0)
				res = ft_cd(&cmd);
			else
				printf("exec\n");
		}
		i += avance + 1;
	}
	return (res);
}
