/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlaarous <zlaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 21:51:05 by zlaarous          #+#    #+#             */
/*   Updated: 2023/04/10 05:30:27 by zlaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "../get_next_line/get_next_line.h"
# include <mlx.h>

typedef struct s_game
{
	int		num_e;
	int		num_p;
	int		num_c;
	int		num_n;
	int		walk_cnt;
	int		hei;
	int		wid;
	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
	int		c;
	char	**map;
	char	*str_line;
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img_wall;
	void	*img_food;
	void	*img_player;
	void	*img_player2;
	void	*img_enemy;
	void	*img4;
	void	*img_exit;
	void	*img_exit2;
	void	*img_exit3;
	void	*img_exit4;
}t_game;

//headers functions :
void	init_stacks(t_game *game);
char	**ft_split(char *s, char c);
void	setting_img(t_game *game);
void	create_image(t_game *game);
int		check_map(t_game *game);
int		check_positions(t_game *game);
int		check_walls(t_game *game);
int		searching(char *str, char *ber);
int		handl_ber(char *str);
int		ft_hooks(t_game *game);
int		ft_keyhook(int keycode, t_game	*game);
int		key_hook(int keycode, t_game *game);
int		closing(t_game *game);
void	move_down(t_game *game);
void	move_up(t_game *game);
int		checkwall2(t_game *game, int x, int y);
int		check_back_track(t_game *game);
int		checkifmapvalid(char **map, int x, int y, t_game *game);
void	position_player(t_game *game);
int		checkwall(char **map, int x, int y, int *e);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	ft_message(void);
void	position_exit(t_game *game);

// tools headers :
size_t	ft_str_len_with_out_new_line(const char *s1);
char	*ft_str_dup_with_out_new_line(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(char *s1);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
void	ft_putchar(char c);
char	*ft_itoa(int n);

#endif
