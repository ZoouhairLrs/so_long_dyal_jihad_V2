/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlaarous <zlaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 21:49:58 by zlaarous          #+#    #+#             */
/*   Updated: 2023/04/06 01:59:12 by zlaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_read(char *filename, t_game *game)
{
	int	fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit(1);
	line = get_next_line(fd);
	game->hei = 0;
	game->str_line = ft_strdup(line);
	free(line);
	while (line)
	{
		// game->hei++;
		line = get_next_line(fd);
		if(line)
			game->str_line = gnl_strjoin(game->str_line, line);
	}
	
	game->map = ft_split(game->str_line, '\n');
	while (game->map[game->hei])
		game->hei++;
	game->wid = gnl_strlen(game->map[0]);
	printf("width == %d ___height == %d\n", game->wid, game->hei);
	close(fd);
	printf("\n%s\n", game->str_line);
}

int	main(int ac, char **av)
{
	t_game	game;
	
	if (ac == 2)
	{
		init_stacks(&game);
		game_read(av[1], &game);
		if (check_map(&game) == 0)
			return (0);
		// printf("%s\n", game.map);
		create_image(&game);
		setting_img(&game);
		mlx_loop(game.mlx_ptr);
	}
	else
	{
		printf("file unreadable");
		exit(1);
	}
	return (0);
}