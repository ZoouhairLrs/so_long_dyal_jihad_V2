/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlaarous <zlaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 07:02:04 by zlaarous          #+#    #+#             */
/*   Updated: 2023/04/08 21:20:46 by zlaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	key_hook(int keycode, t_game *game)
{
	ft_keyhook(keycode, game);
	return (0);
}

int	ft_keyhook(int keycode, t_game	*game)
{
	if (keycode == 53)
		closing(game);
	else if (keycode == 13 || keycode == 126)
		move_up(game);
	else if (keycode == 1 || keycode == 125)
		move_down(game);
	else if (keycode == 0 || keycode == 123)
		move_left(game);
	else if (keycode == 2 || keycode == 124)
		move_right(game);
	return (0);
}

int	ft_hooks(t_game *game)
{
	mlx_hook(game->mlx_win, 2, (1L << 0), &key_hook, game);
	mlx_hook(game->mlx_win, 17, 0, &closing, game);
	return (0);
}
