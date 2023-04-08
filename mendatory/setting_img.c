/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlaarous <zlaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 22:38:44 by zlaarous          #+#    #+#             */
/*   Updated: 2023/04/08 01:16:15 by zlaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_image(t_game *game, int wid, int hei)
{
	if (game->map[hei][wid] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->img_wall, wid * 64, hei * 64);
	else if (game->map[hei][wid] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->img_food, wid * 64, hei * 64);
	else if (game->map[hei][wid] == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->img_player, wid * 64, hei * 64);
	else if (game->map[hei][wid] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->img_exit, wid * 64, hei * 64);
	else
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->img4, wid * 64, hei * 64);
}

void	setting_img(t_game *game)
{
	int	hei;
	int	wid;
	char *str;

	hei = 0;
	while (hei < game->hei)
	{
		wid = 0;
		while (wid < game->wid)
		{
			draw_image(game, wid, hei);
			wid++;
		}
		hei++;
	}
}
