/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:18:59 by htouil            #+#    #+#             */
/*   Updated: 2023/07/13 19:11:04 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_ptr(char *av, t_exec *exec)
{
	exec->cmd = ft_strcpy(av);
	exec->opt = NULL;
	exec->param = NULL;
}

void	wdopt_utils(int i, t_exec *exec)
{
	if (exec->cmd[i] == ' ' && exec->cmd[i + 1] == '-'
		&& ft_isalnum(exec->cmd[i + 2]))
	{
		exec->cmd[i] = '\0';
		exec->opt = exec->cmd + i + 1;
	}
	else if (exec->cmd[i] == ' ' && exec->cmd[i + 1] == 39)
	{
		exec->cmd[i] = '\0';
		exec->param = exec->cmd + i + 1;
	}
}

char	**get_lcommand_withopt(char *av)
{
	int		i;
	char	**command;
	char	*tmp;
	t_exec	exec;

	init_ptr(av, &exec);
	tmp = exec.cmd;
	exec.cmd = ft_strtrim(exec.cmd, " ");
	free(tmp);
	i = -1;
	while (exec.cmd[++i])
		wdopt_utils(i, &exec);
	command = malloc(4 * sizeof(char *));
	command[0] = ft_strtrim(exec.cmd, " ");
	command[1] = ft_strtrim(exec.opt, " ");
	command[2] = ft_strtrim(exec.param, "'");
	command[3] = NULL;
	free(exec.cmd);
	return (command);
}

char	**get_lcommand_withoutopt(char *av)
{
	int		i;
	char	**command;
	char	*tmp;
	t_exec	exec;

	init_ptr(av, &exec);
	tmp = exec.cmd;
	exec.cmd = ft_strtrim(exec.cmd, " ");
	free(tmp);
	i = -1;
	while (exec.cmd[++i])
	{
		if (exec.cmd[i] == ' ' && exec.cmd[i + 1] == 39)
		{
			exec.cmd[i] = '\0';
			exec.param = exec.cmd + i + 1;
		}
	}
	command = malloc(3 * sizeof(char *));
	command[0] = ft_strtrim(exec.cmd, " ");
	command[1] = ft_strtrim(exec.param, "'");
	command[2] = NULL;
	free(exec.cmd);
	return (command);
}
