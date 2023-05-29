#include "pipex.h"

void	child_proc(char **av, char **envp, int *pipefd)
{
	int fd1;
	
	fd1 = open(av[1], O_RDONLY, 0777);
	if (fd1 == -1)
	{
		write(2, "Error\nOpenning the infile failed!\n", 34);
		exit(1);
	}
	dup2(fd1, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[0]);
	execute(av[2], envp);
	close(fd1);
}

void	parent_proc(char **av, char **envp, int *pipefd)
{
	int	fd2;

	fd2 = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd2 == -1)
	{
		write(2, "Error\nOpenning the outfile failed!\n", 34);
		exit(1);
	}
	dup2(pipefd[0], STDIN_FILENO);
	dup2(fd2, STDOUT_FILENO);
	close(pipefd[1]);
	execute(av[3], envp);
	close(fd2);
}

int	main(int ac, char **av, char **envp)
{
	int		pipefd[2];
	pid_t	pid;

	if (ac != 5)
	{
		write(2, "Error\nNot enough arguments!\n", 28);
		return (1);
	}
	if (pipe(pipefd) == -1)
	{
		write(2, "Error\nPipe not created!\n", 24);
		return (1);
	}
	pid = fork();
	if (pid == -1)
	{
		write(2, "Error\nChild process not created!\n", 33);
		return (1);
	}
	if (pid == 0)
	{
		child_proc(av, envp, pipefd);
	}
	waitpid(pid, NULL, 0);
	parent_proc(av, envp, pipefd);
    return (0);
}
