/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlaarous <zlaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 22:56:03 by zlaarous          #+#    #+#             */
/*   Updated: 2023/04/08 21:30:23 by zlaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_walls(t_game *game)
{
	int	i;
	int	j;
	int	len_col;
	int	len_row;

	len_col = gnl_strlen(game->map[0]);
	i = 0;
	j = 0;
	len_row = 0;
	while (game->map[len_row])
		len_row++;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[0][j] != '1' || game->map[len_row - 1][j] != '1' ||
				game->map[i][0] != '1' || game->map[i][len_col - 1] != '1')
			{
				ft_putstr("invalid map!");
				return (0);
			}
			j++;
		}
		if (j != len_col)
			return (0);
		i++;
	}
	return (1);
}

int	check_positions(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'E')
				game->num_e++;
			if (game->map[i][j] == 'P')
				game->num_p++;
			if (game->map[i][j] == 'C')
				game->num_c++;
			if (game->map[i][j] == 'N')
				game->num_n++;
			j++;
		}
		i++;
	}
	if (game->num_e != 1 || game->num_p != 1
		|| game->num_c == 0 || game->num_n == 0)
	{
		ft_putstr("problem caracteres!");
		return (0);
	}
	return (1);
}

int	validation_caracters(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != '0' && game->map[i][j] != '1' &&
				game->map[i][j] != 'C' && game->map[i][j] != 'E' &&
				game->map[i][j] != 'P' &&
				game->map[i][j] != 'N')
			{
				ft_putstr("Some caracteres is missing!");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_map(t_game *game)
{
	int	j;

	j = 0;
	if (check_positions(game) == 0)
		return (0);
	if (check_walls(game) == 0)
		return (0);
	if (validation_caracters(game) == 0)
		return (0);
	if (check_back_track(game) == 0)
		return (0);
	return (1);
}
