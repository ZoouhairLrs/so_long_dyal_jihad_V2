/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlaarous <zlaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 07:18:25 by zlaarous          #+#    #+#             */
/*   Updated: 2023/04/08 00:20:49 by zlaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int checkwall2(t_game *game, int y, int x)
{		
	if(game->map[y][x] == '1')
		return (1);
	if(game->map[y][x] == 'C')
	{
		game->c++;
	}
	if(game->map[y][x] == 'E')
	{
		if(game->num_c == game->c)
		{
			ft_putstr("win !!");
			exit(0);
		}
		return(1);
	}
	if(x <= 0 || y <= 0 || x >= game->wid || y >= game->hei)
		return (1);
	return (0);
}

void	move_up(t_game *game)
{
	int	i;

	i = 0;
	if(!checkwall2(game, game->P_Y - 1, game->P_X))
	{
		game->map[game->P_Y - 1][game->P_X] = 'P';
		game->map[game->P_Y][game->P_X] = '0';
		game->P_Y -=1;
		game->walk_cnt++;
		setting_img(game);
	}
	ft_putnbr(game->walk_cnt);
	write(1, "\n", 1);
}
