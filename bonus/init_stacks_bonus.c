/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlaarous <zlaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 21:51:54 by zlaarous          #+#    #+#             */
/*   Updated: 2023/04/11 21:31:03 by zlaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_stacks(t_game *game)
{
	game->num_e = 0;
	game->num_p = 0;
	game->num_c = 0;
	game->num_n = 0;
	game->hei = 0;
	game->wid = 0;
	game->map = 0;
	game->c = 0;
	game->p_x = 0;
	game->p_y = 0;
	game->e_x = 0;
	game->e_y = 0;
	game->str_line = 0;
	game->mlx_ptr = 0;
	game->mlx_win = 0;
	game->img_wall = 0;
	game->img_food = 0;
	game->img_player = 0;
	game->img4 = 0;
	game->img_exit = 0;
	game->walk_cnt = 0;
}
