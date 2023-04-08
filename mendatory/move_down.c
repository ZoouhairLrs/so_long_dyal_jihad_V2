/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlaarous <zlaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 07:18:41 by zlaarous          #+#    #+#             */
/*   Updated: 2023/04/08 02:44:20 by zlaarous         ###   ########.fr       */
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
	if (game->map[game->P_Y][game->P_X] == 'C' && game->num_c == game->c)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->img_exit4, game->e_x * 64, game->e_y * 64);
	}
	ft_putnbr(game->walk_cnt);
	write(1, "\n", 1);
}
