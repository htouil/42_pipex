#include "../pipex.h"

int ft_strnstr(char *h, char *n, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (n[j] == '\0')
		return (1);
	while (h[i] != '\0' && n[j] != '\0' && i < len)
	{
		while (h[i + j] == n[j] && h[i + j] != '\0' && i + j < len)
			j++;
		if (n[j] == '\0')
			return (0);
		j = 0;
		i++;
	}
	return (1);
}