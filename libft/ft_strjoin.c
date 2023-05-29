#include "../pipex.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ss;
	int	i;
	int	j;

	ss = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ss)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j] != '\0')
	{
		ss[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		ss[i] = s2[j];
		i++;
		j++;
	}
	ss[i] = '\0';
	return (ss);
}