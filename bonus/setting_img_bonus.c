/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_img_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlaarous <zlaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 22:38:44 by zlaarous          #+#    #+#             */
/*   Updated: 2023/04/12 00:59:50 by zlaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	animation(t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
		game->img_exit4, game->e_x * 64, game->e_y * 64);
}

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
	else if (game->map[hei][wid] == 'N')
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->img_enemy, wid * 64, hei * 64);
	else
		mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
			game->img4, wid * 64, hei * 64);
	if (game->num_c == game->c)
	{
		animation(game);
	}
}

void	setting_img(t_game *game)
{
	int		hei;
	int		wid;
	char	*str;

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
	str = ft_itoa(game->walk_cnt);
	mlx_string_put(game->mlx_ptr, game->mlx_win, 10, 30, 0xccccff, "moves:");
	mlx_string_put(game->mlx_ptr, game->mlx_win, 70, 30, 0xccccff, str);
}
