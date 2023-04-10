/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlaarous <zlaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 07:18:41 by zlaarous          #+#    #+#             */
/*   Updated: 2023/04/10 05:36:49 by zlaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_down(t_game *game)
{
	if (!checkwall2(game, game->p_y + 1, game->p_x))
	{
		game->map[game->p_y + 1][game->p_x] = 'P';
		game->map[game->p_y][game->p_x] = '0';
		game->p_y += 1;
		game->walk_cnt++;
		setting_img(game);
		ft_putnbr(game->walk_cnt);
		write(1, "\n", 1);
	}
}
