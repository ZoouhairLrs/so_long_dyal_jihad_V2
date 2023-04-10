/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlaarous <zlaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 22:44:24 by zlaarous          #+#    #+#             */
/*   Updated: 2023/04/10 00:53:30 by zlaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_image(t_game *game)
{
	int	img_width;
	int	img_height;

	printf("here!\n");
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		exit(0);
	game->mlx_win = mlx_new_window(game->mlx_ptr, game->wid * 64,
			game->hei * 64, "so_long");
	if (!game->mlx_win)
		exit(0);
	game->img_wall = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/wall.xpm", &img_width, &img_height);
	game->img_food = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/food.xpm", &img_width, &img_height);
	game->img_player = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/player.xpm", &img_width, &img_height);
	game->img4 = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/land.xpm", &img_width, &img_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/exit.xpm", &img_width, &img_height);
	game->img_exit4 = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/exit4.xpm", &img_width, &img_height);
}
