/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlaarous <zlaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 22:38:44 by zlaarous          #+#    #+#             */
/*   Updated: 2023/04/06 01:54:01 by zlaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	setting_img(t_game *game)
{
	int	hei;
	int	wid;
	
	hei = 0;
	while (hei < game->hei)
	{
		wid = 0;
		while (wid < game->wid)
		{
			if (game->map[hei][wid] == '1')
			{
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_wall, wid * 100, hei * 100);
			} else if (game->map[hei][wid] == 'C')
			{
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_food, wid * 100, hei * 100);
			}else if (game->map[hei][wid] == 'P')
			{
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_player, wid * 100, hei * 100);
			} else if (game->map[hei][wid] == 'E')
			{
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img_exit, wid * 100, hei * 100);
			} else
			{
				mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img4, wid * 100, hei * 100);
			}
			wid++;
		}
		hei++;
	}
	printf("hei == %d ___ wid == %d\n", hei, wid);
}
