/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_track_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlaarous <zlaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 07:33:24 by zlaarous          #+#    #+#             */
/*   Updated: 2023/04/08 22:37:43 by zlaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	checkwall(char **map, int x, int y, int *e)
{
	if (map[x][y] == '1')
		return (1);
	if (map[x][y] == 'E')
	{
		*e += 1;
		return (1);
	}
	return (0);
}

void	position_player(t_game *game)
{
	int	l;
	int	d;

	l = 0;
	d = 0;
	while (l < game->hei)
	{
		d = 0;
		while (d < game->wid)
		{
			if (game->map[l][d] == 'P')
			{
				game->p_x = d;
				game->p_y = l;
			}
			d++;
		}
		l++;
	}
}

void	position_exit(t_game *game)
{
	int	l;
	int	d;

	l = 0;
	d = 0;
	while (l < game->hei)
	{
		d = 0;
		while (d < game->wid)
		{
			if (game->map[l][d] == 'E')
			{
				game->e_x = d;
				game->e_y = l;
			}
			d++;
		}
		l++;
	}
}

int	checkifmapvalid(char **map, int x, int y, t_game *game)
{
	static int	c;
	static int	e;

	if (map[x][y] == 'C')
		c++;
	map[x][y] = '1';
	if (checkwall(map, x, y + 1, &e) == 0)
	{
		if (checkifmapvalid(map, x, y + 1, game) == 1)
			return (1);
	}
	if (c == game->num_c && e > 0)
		return (1);
	if (checkwall(map, x, y - 1, &e) == 0)
	{
		if (checkifmapvalid(map, x, y - 1, game) == 1)
			return (1);
	}
	if (c == game->num_c && e > 0)
		return (1);
	if (checkwall(map, x + 1, y, &e) == 0)
	{
		if (checkifmapvalid(map, x + 1, y, game) == 1)
			return (1);
	}
	if (c == game->num_c && e > 0)
		return (1);
	if (checkwall(map, x - 1, y, &e) == 0)
	{
		if (checkifmapvalid(map, x - 1, y, game) == 1)
			return (1);
	}
	if (c == game->num_c && e > 0)
		return (1);
	return (0);
}

int	check_back_track(t_game *game)
{
	int		k;
	char	**map;

	position_player(game);
	position_exit(game);
	k = 0;
	map = malloc(sizeof(char *) * (game->hei + 1));
	while (k < game->hei)
	{
		map[k] = ft_strdup(game->map[k]);
		k++;
	}
	map[k] = NULL;
	if (checkifmapvalid(map, game->p_x, game->p_y, game) == 0)
	{
		ft_putstr ("map not valid \n");
		exit(1);
		return (0);
	}
	return (1);
}
