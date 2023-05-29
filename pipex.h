#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

void	execute(char *av, char **envp);
int     ft_strnstr(char *h, char *n, int len);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char *s, char c);
int	    ft_strlen(char *str);

#endif