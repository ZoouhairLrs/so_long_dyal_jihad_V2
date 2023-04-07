/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlaarous <zlaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 07:18:41 by zlaarous          #+#    #+#             */
/*   Updated: 2023/04/07 07:13:55 by zlaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_down(t_game *game)
{
	if(!checkwall2(game, game->P_Y + 1, game->P_X))
	{
		game->map[game->P_Y + 1][game->P_X] = 'P';
		game->map[game->P_Y][game->P_X] = '0';
		game->P_Y += 1;
		game->walk_cnt++;
		setting_img(game);
	}
	ft_putnbr(game->walk_cnt);
	write(1, "\n", 1);
}
