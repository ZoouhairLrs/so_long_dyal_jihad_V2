/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlaarous <zlaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 21:32:13 by zlaarous          #+#    #+#             */
/*   Updated: 2023/04/09 20:19:17 by zlaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;
	int			len;
	char		*frees;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	str = gnl_read_str(fd, str);
	if (!str)
		return (0);
	len = gnl_strlen(str);
	line = gnl_sub_line(str);
	frees = str;
	str = gnl_substr(str, gnl_strchr(str, '\n') - str + 1,
			len - (gnl_strchr(str, '\n') - str + 1));
	return (free(frees), line);
}

char	*gnl_read_str(int fd, char *save)
{
	char	*buff;
	int		r_b;
	int		i;

	i = 0;
	r_b = 1;
	buff = malloc((1 + 1) * sizeof(char));
	if (!buff)
		return (free(save), NULL);
	while (r_b > i)
	{
		r_b = read(fd, buff, BUFFER_SIZE);
		if (r_b < i)
			return (free(buff), free(save), NULL);
		buff[r_b] = '\0';
		save = gnl_strjoin(save, buff);
	}
	free(buff);
	return (save);
}

size_t	gnl_strlcpy(char *dst, char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (dstsize > 0)
	{
		while (src[i] != '\0' && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[j] != '\0')
	{
		j++;
	}
	return (j);
}

size_t	gnl_strlcat(char *dst, char *src, size_t size)
{
	size_t	ls;
	size_t	ld;
	size_t	i;
	size_t	j;

	if (size == 0 || size < gnl_strlen(dst))
		return (size + gnl_strlen(src));
	ld = gnl_strlen(dst);
	ls = gnl_strlen(src);
	i = 0;
	j = ld;
	while (src[i] != 0 && j + 1 < size)
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (ls + ld);
}
