/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 22:30:45 by htouil            #+#    #+#             */
/*   Updated: 2023/09/29 12:46:08 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_proc1(char **av, char **envp, int *pipefd)
{
	int	fd1;

	fd1 = open(av[1], O_RDONLY, 0777);
	if (fd1 == -1)
	{
		write(2, "Error\nOpenning the infile failed!\n", 34);
		exit(1);
	}
	dup2(fd1, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[0]);
	close(pipefd[1]);
	close(fd1);
	execute(av[2], envp);
}

void	child_proc2(char **av, char **envp, int *pipefd)
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
	close(pipefd[0]);
	close(pipefd[1]);
	close(fd2);
	execute(av[3], envp);
}

void	forking(char **av, char **envp, int *pipefd)
{
	pid_t	pid1;
	pid_t	pid2;

	pid1 = fork();
	if (pid1 < 0)
		return (perror("Fork: "));
	else if (pid1 == 0)
		child_proc1(av, envp, pipefd);
	else
	{
		pid2 = fork();
		if (pid2 < 0)
			return (perror("Fork: "));
		else if (pid2 == 0)
			child_proc2(av, envp, pipefd);
		else
		{
			close(pipefd[0]);
			close(pipefd[1]);
			waitpid(pid2, NULL, 0);
		}
		waitpid(pid1, NULL, 0);
	}
}

int	main(int ac, char **av, char **envp)
{
	int		pipefd[2];

	if (ac != 5)
	{
		write(2, "Error\nIncorrect summation of arguments!\n", 34);
		return (1);
	}
	if (pipe(pipefd) == -1)
	{
		write(2, "Error\nPipe not created!\n", 24);
		return (1);
	}
	forking(av, envp, pipefd);
	return (0);
}
