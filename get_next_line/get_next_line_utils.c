/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlaarous <zlaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 10:11:53 by zlaarous          #+#    #+#             */
/*   Updated: 2023/03/29 22:43:31 by zlaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strchr(const char *str, char c)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&str[i]);
	return (NULL);
}

size_t	gnl_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*gnl_sub_line(char *str)
{
	int		i;
	char	*str_save;
	int		len;

	i = 0;
	if (!str)
		return (NULL);
	len = (gnl_strchr(str, '\n') - str) + 1;
	i = 0;
	str_save = gnl_substr(str, 0, len);
	return (str_save);
}

char	*gnl_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	size;

	if (gnl_strlen(s) <= start)
		return (0);
	i = 0;
	size = gnl_strlen(s + start);
	if (size < len)
		len = size;
	str = malloc((len + 1) * sizeof(char));
	if (!str || !s)
		return (0);
	while (i < len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		if (!s1)
			return (free(s1), NULL);
		s1[0] = '\0';
	}
	if (!s2)
		return (free(s1), NULL);
	s1_len = gnl_strlen(s1);
	s2_len = gnl_strlen(s2);
	str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (str == NULL)
		return (free(s1), NULL);
	gnl_strlcpy(str, s1, s1_len + 1);
	gnl_strlcat(str + s1_len, s2, s2_len + 1);
	return (free(s1), str);
}
