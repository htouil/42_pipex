/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 22:30:51 by htouil            #+#    #+#             */
/*   Updated: 2023/07/13 18:10:08 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_exec
{
	char	*cmd;
	char	*opt;
	char	*param;
	int		i;
}		t_exec;

//libft functions:
int		ft_strnstr(char *h, char *n, int len);
char	*ft_substr(char *s, int start, int len);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char *s, char c);
int		ft_strlen(char *str);
int		ft_strfchr(char *s, char c);
int		ft_isalnum(int a);
char	*ft_strcpy(char *src);
char	*ft_strtrim(char *s1, char *set);

//pipex functions:
void	execute(char *av, char **envp);
char	**get_lcommand_withopt(char *av);
char	**get_lcommand_withoutopt(char *av);
void	free_arr(char **arr);

#endif
