/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlaarous <zlaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 21:32:37 by zlaarous          #+#    #+#             */
/*   Updated: 2023/04/09 20:22:21 by zlaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*gnl_read_str(int fd, char *save);
char	*gnl_strchr(const char *str, char c);
size_t	gnl_strlen(char *str);
char	*gnl_sub_line(char *str);
size_t	gnl_strlcpy(char *dst, char *src, size_t dstsize);
size_t	gnl_strlcat(char *dst, char *src, size_t size);
char	*gnl_substr(char *s, unsigned int start, size_t len);
char	*gnl_strjoin(char *s1, char *s2);

#endif
