/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <htouil@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 21:06:11 by htouil            #+#    #+#             */
/*   Updated: 2023/07/13 18:16:31 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strchr(char *s, int c)
{
	char	a;

	a = (char)c;
	while (*s)
	{
		if (*s == a)
			return (s);
		s++;
	}
	if (a == '\0')
		return (s);
	return (0);
}

char	*ft_strrchr(char *s, int c)
{
	char	a;
	int		len;

	a = (char)c;
	len = ft_strlen(s);
	s = s + len;
	while (len)
	{
		if (*s == a)
			return (s);
		s--;
		len--;
	}
	if (*s == a)
		return (s);
	return (NULL);
}

char	*ft_strtrim(char *s1, char *set)
{
	char	*ss;
	int		s_len;

	if (!s1 || !set)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	s_len = ft_strlen(s1);
	while (s_len && ft_strrchr(set, s1[s_len]))
		s_len--;
	ss = ft_substr(s1, 0, s_len + 1);
	return (ss);
}
