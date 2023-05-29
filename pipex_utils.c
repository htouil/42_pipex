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
	i = 0;
	while (paths_list[i])
	{
		part_path = ft_strjoin(paths_list[i], "/");
		final_path = ft_strjoin(part_path, command);
		if (access(final_path, F_OK) == 0)
			return (final_path);
		i++;
	}
	return (NULL);
}

void	execute(char *av, char **envp)
{
	char	**command;
	char	*path;
	
	command = ft_split(av, ' ');
	path = find_path(command[0], envp);
	if (path == NULL)
	{
		write(2, "Error\nLibrary path not found!\n", 30);
		exit(1);
	}
	if (execve(path, command, envp) == -1)
	{
		write(2, "Error\nCommand execution failed!\n", 32);
		exit(1);
	}
}
