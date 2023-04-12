/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlaarous <zlaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 07:59:03 by zlaarous          #+#    #+#             */
/*   Updated: 2023/04/11 21:52:06 by zlaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_left(t_game *game)
{
	if (!checkwall2(game, game->p_y, game->p_x - 1))
	{
		game->map[game->p_y][game->p_x - 1] = 'P';
		game->map[game->p_y][game->p_x] = '0';
		game->p_x -= 1;
		game->walk_cnt++;
		setting_img(game);
		ft_putnbr(game->walk_cnt);
		write(1, "\n", 1);
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->img_player2, game->p_x * 64, game->p_y * 64);
	}
}
