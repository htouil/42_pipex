/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 22:31:00 by htouil            #+#    #+#             */
/*   Updated: 2023/07/14 16:54:30 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char *command, char **envp)
{
	char	**paths_list;
	char	*part_path;
	char	*final_path;
	int		i;

	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH", 4) == 1)
		i++;
	paths_list = ft_split(envp[i] + 5, ':');
	i = -1;
	while (paths_list[++i])
	{
		part_path = ft_strjoin(paths_list[i], "/");
		final_path = ft_strjoin(part_path, command);
		if (access(final_path, F_OK) == 0)
		{
			free(part_path);
			free_arr(paths_list);
			return (final_path);
		}
		free(part_path);
		free(final_path);
	}
	free_arr(paths_list);
	return (NULL);
}

int	check_opt(char	*av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] == ' ' && av[i + 1] == '-' && ft_isalnum(av[i + 2]))
			return (1);
		i++;
	}
	return (0);
}

char	**get_command(char *av)
{
	char	**command;

	command = NULL;
	if (check_opt(av) == 1 && ft_strfchr(av, 39) == 1)
		command = get_lcommand_withopt(av);
	else if (check_opt(av) == 0 && ft_strfchr(av, 39) == 1)
		command = get_lcommand_withoutopt(av);
	else
		command = ft_split(av, ' ');
	return (command);
}

void	execute(char *av, char **envp)
{
	char	**command;
	char	*path;

	command = get_command(av);
	path = find_path(command[0], envp);
	if (path == NULL)
	{
		write(2, "Error\nLibrary path not found!\n", 30);
		free_arr(command);
		exit(1);
	}
	if (execve(path, command, envp) == -1)
	{
		write(2, "Error\nCommand execution failed!\n", 32);
		free_arr(command);
		free(path);
		exit(1);
	}
}
