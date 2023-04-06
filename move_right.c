/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlaarous <zlaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 07:59:27 by zlaarous          #+#    #+#             */
/*   Updated: 2023/04/06 21:19:40 by zlaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_game *game)
{
	if(!checkwall2(game, game->P_Y, game->P_X + 1))
	{
		game->map[game->P_Y][game->P_X + 1] = 'P';
		game->map[game->P_Y][game->P_X] = '0';
		game->P_X += 1;
		game->walk_cnt++;
		setting_img(game);
	}
	printf("%d\n", game->walk_cnt);
	printf("x == %d || y == %d \n",game->P_X,game->P_Y);
}
