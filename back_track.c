/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_track.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlaarous <zlaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 07:33:24 by zlaarous          #+#    #+#             */
/*   Updated: 2023/04/07 03:50:04 by zlaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int checkwall(char **map, int x, int y, int *e)
{
	if(map[x][y] =='1')
		return 1;
	if(map[x][y] == 'E')
	{
		*e+=1;
		return(1);
	}
	return 0;
}

void	position_player(t_game *game)
{
	int l;
	int d;

	l = 0;
	d = 0;
	
	while(l < game->hei)
	{
		d = 0;
		while(d < game->wid)
		{
			if(game->map[l][d] == 'P')
			{
				game->P_X = d;
				game->P_Y= l;
			}
			d++;
		}
		l++;
	}
}

int	checkifmapvalid(char **map, int x, int y, t_game *game)
{
	static int c;
	static int e;

	if(map[x][y] == 'C')
		c++;
	map[x][y] = '1';
	if(checkwall(map, x, y + 1, &e) == 0)
	{
		if (checkifmapvalid(map, x, y + 1, game) == 1)
			return (1);
	}
	if(c == game->num_c && e > 0)
		return (1);
	if(checkwall(map, x, y - 1, &e) == 0)
	{
		if (checkifmapvalid(map, x, y - 1, game) == 1)
			return (1);
	}
	if(c == game->num_c && e > 0)
		return (1);
	if(checkwall(map,x + 1,y,&e) == 0)
	{
		if (checkifmapvalid(map, x + 1, y, game) == 1)
			return (1);
	}
	if(c == game->num_c && e > 0)
		return (1);
	if(checkwall(map, x - 1, y, &e) == 0)
	{
		if (checkifmapvalid(map, x - 1, y, game) == 1)
			return (1);
	}
	if(c == game->num_c && e > 0)
		return (1);
	return (0);
}

int	check_back_track(t_game *game)
{
	int		k;
	char	**map;
	
	position_player(game);
	k = 0;
	map = malloc(sizeof(char *) * (game->hei + 1));
	while(k < game->hei)
	{
		map[k] = ft_strdup(game->map[k]);
		k++;
	}
	map[k] = NULL;
	if (checkifmapvalid(map, game->P_X, game->P_Y, game) == 0)
	{
		printf("map not valid \n");
		exit(1);
		return (0);
	}
	return (1);
}
