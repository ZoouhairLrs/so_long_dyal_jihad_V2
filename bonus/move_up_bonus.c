/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlaarous <zlaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 07:18:25 by zlaarous          #+#    #+#             */
/*   Updated: 2023/04/10 01:17:51 by zlaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	checkwall2(t_game *game, int y, int x)
{		
	if (game->map[y][x] == '1')
		return (1);
	if (game->map[y][x] == 'N')
	{
		ft_putstr ("loser !!");
		exit(0);
	}
	if (game->map[y][x] == 'C')
	{
		game->c++;
	}
	if (game->map[y][x] == 'E')
	{
		if (game->num_c == game->c)
		{
			ft_putstr ("win !!");
			exit(0);
		}
		return (1);
	}
	if (x <= 0 || y <= 0 || x >= game->wid || y >= game->hei)
		return (1);
	return (0);
}

void	move_up(t_game *game)
{
	int	i;

	i = 0;
	if (!checkwall2(game, game->p_y - 1, game->p_x))
	{
		game->map[game->p_y - 1][game->p_x] = 'P';
		game->map[game->p_y][game->p_x] = '0';
		game->p_y -= 1;
		game->walk_cnt++;
		setting_img(game);
		ft_putnbr(game->walk_cnt);
		write(1, "\n", 1);
		if (game->map[game->p_y][game->p_x] == 'C' && game->num_c == game->c)
		{
			mlx_put_image_to_window(game->mlx_ptr, game->mlx_win,
				game->img_exit2, game->e_x * 64, game->e_y * 64);
		}
	}
}
