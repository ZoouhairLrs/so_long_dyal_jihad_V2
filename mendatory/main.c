/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlaarous <zlaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 21:49:58 by zlaarous          #+#    #+#             */
/*   Updated: 2023/04/11 20:54:24 by zlaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft__while(t_game *game, char *line)
{
	int	i;

	while (line)
	{
		i = 0;
		while (line[i] != '\0' && line[i] != '\n')
			i++;
		if (i != game->wid)
		{
			free(line);
			ft_message();
		}
	}
}

void	game_read(char *filename, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_message();
	line = get_next_line(fd);
	game->hei = 0;
	game->str_line = ft_strdup(line);
	free(line);
	while (line)
	{
		line = get_next_line(fd);
		// ft__while(game, line);
		if (line)
			game->str_line = gnl_strjoin(game->str_line, line);
	}
	game->map = ft_split(game->str_line, '\n');
	while (game->map[game->hei])
		game->hei++;
	game->wid = gnl_strlen(game->map[0]);
	close(fd);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2)
	{
		if (handl_ber(av[1]) == 0)
			return (0);
		init_stacks(&game);
		game_read(av[1], &game);
		if (check_map(&game) == 0)
			return (0);
		create_image(&game);
		setting_img(&game);
		ft_hooks(&game);
		mlx_loop(game.mlx_ptr);
	}
	else
	{
		ft_putstr("Error!");
		exit(1);
	}
	return (0);
}
