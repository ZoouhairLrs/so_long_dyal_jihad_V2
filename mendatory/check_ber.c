/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ber.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlaarous <zlaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 06:21:54 by zlaarous          #+#    #+#             */
/*   Updated: 2023/04/08 00:08:39 by zlaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	searching(char *str, char *ber)
{
	int i;
	int len;

	len = gnl_strlen(str) - 1;
	if(str[len] == ber[3] && str[len - 1] == ber[2] && str[len - 2] == ber[1] 
		&& str[len - 3] == ber[0])
		return (1);
	return (0);
}

int handl_ber(char *str)
{
	if (searching(str, ".ber") == 0)
	{
		ft_putstr("map extansion is not .ber Grrr.");
		return (0);
	}
	return (1);
}
