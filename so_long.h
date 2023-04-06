/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlaarous <zlaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 21:51:05 by zlaarous          #+#    #+#             */
/*   Updated: 2023/04/06 06:21:21 by zlaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "./get_next_line/get_next_line.h"
# include <mlx.h>

typedef struct s_game{
	int	num_e;
	int	num_p;
	int	num_c;
	int	walk_cnt;
	int hei;
	int wid;
	int	P_X;
	int	P_Y;
	char **map;
	char *str_line;
	void *mlx_ptr;
	void *mlx_win;
	void *img_wall;
	void *img_food;
	void *img_player;
	void *img4;
	void *img_exit;
} t_game;

//headers functions :
void	init_stacks(t_game *game);
char	**ft_split(char *s, char c);
void	setting_img(t_game *game);
void	create_image(t_game *game);
int		check_map(t_game *game);
int		check_positions(t_game *game);
int		check_walls(t_game *game);
int		searching(char *str, char *ber);


// tools headers :
size_t	ft_str_len_with_out_new_line(const char *s1);
char	*ft_str_dup_with_out_new_line(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(char *s1);
void	ft_putstr(char *str);

#endif
