/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlaarous <zlaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 07:59:03 by zlaarous          #+#    #+#             */
/*   Updated: 2023/04/08 00:20:59 by zlaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_left(t_game *game)
{
	if(!checkwall2(game, game->P_Y, game->P_X - 1))
	{
		game->map[game->P_Y][game->P_X - 1] = 'P';
		game->map[game->P_Y][game->P_X] = '0';
		game->P_X -= 1;
		game->walk_cnt++;
		setting_img(game);
	}
	if (game->map[game->P_Y][game->P_X] == 'C' && game->num_c == game->c)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->img_exit2, game->e_x * 64, game->e_y * 64);
	}
	ft_putnbr(game->walk_cnt);
	write(1, "\n", 1);
}