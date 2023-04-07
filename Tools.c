/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlaarous <zlaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 22:06:04 by zlaarous          #+#    #+#             */
/*   Updated: 2023/04/07 03:46:15 by zlaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_str_len_with_out_new_line(const char *s1)
{
	size_t	i;
	size_t	j;

	if (!s1)
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != '\0' && s1[i] != '\n')
	{
		if (s1[i] == '\n')
			j++;
		i++;
	}
	return (i - j);
}

char	*ft_str_dup_with_out_new_line(const char *s1)
{
	char	*ma;
	int		len;
	int		i;

	len = ft_str_len_with_out_new_line(s1) + 1;
	ma = malloc(sizeof (char) * len);
	if (ma == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0' )
	{
		if (s1[i] == '\n')
			i++;
		ma[i] = s1[i];
		i++;
	}
	ma[i] = '\0';
	return (ma);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	new_len;

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
	new_len = s1_len + s2_len;
	while (s1_len > 0 && s1[s1_len - 1] == '\n')
	{
		s1_len--;
		new_len--;
	}
	str = malloc(sizeof(char) * (new_len + 1));
	if (str == NULL)
		return (free(s1), NULL);
	gnl_strlcpy(str, s1, s1_len);
	gnl_strlcat(str + s1_len, s2, s2_len);
	return (free(s1), str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	size;

	if (gnl_strlen(s) < start)
		return (ft_strdup("\0"));
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

char	*ft_strdup(char *s1)
{
	char	*ma;
	int		len;
	int		i;

	len = gnl_strlen(s1) + 1;
	ma = malloc(sizeof (char) * len);
	if (ma == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		ma[i] = s1[i];
		i++;
	}
	ma[i] = '\0';
	return (ma);
}
