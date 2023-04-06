/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlaarous <zlaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 07:18:25 by zlaarous          #+#    #+#             */
/*   Updated: 2023/04/06 07:51:41 by zlaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int checkwall2(t_game *game, int x, int y)
{
	int static c;
	if(game->map[x][y] == '1')
		return 1;
	if(game->map[x][y] == 'C')
		c++;
	if(game->map[x][y] == 'E')
	{
		if(game->num_c == c)
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
	int	c;

	i = 0;
	if(!checkwall2(game, game->P_X, game->P_Y - 1))
	{
		game->map[game->P_Y - 1][game->P_X] = 'P';
		game->map[game->P_Y][game->P_X] = '0';
		game->P_Y -=1;
		game->walk_cnt++;
		setting_img(game);
	}
	printf("%d\n", game->walk_cnt);
	printf("x == %d || y == %d \n",game->P_X,game->P_Y);
}
