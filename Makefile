# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zlaarous <zlaarous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/05 21:50:15 by zlaarous          #+#    #+#              #
#    Updated: 2023/04/07 07:05:58 by zlaarous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

SRCS		= 		main.c \
					./get_next_line/get_next_line.c \
					./get_next_line/get_next_line_utils.c \
					init_stacks.c\
					ft_split.c \
					Tools.c \
					create_image.c \
					setting_img.c \
					check_map.c \
					ft_message.c \
					ft_putstr.c \
					check_ber.c \
					ft_hook.c \
					closing_pross.c \
					move_up.c \
					move_down.c \
					move_left.c \
					move_right.c \
					back_track.c \
					ft_putnbr.c \
					ft_putchar.c \

INCLUDE 	= so_lonh.h

OBJS		= $(SRCS:%.c=%.o)

FLAG = -Wall -Wextra -Werror

SUPER_FLAG =  -I /usr/X11/include -l mlx -framework OpenGL -framework AppKit



all: $(NAME)

%.o: %.c $(INCLUDE)
	$(CC) $(FLAG) -Imlx -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(SUPER_FLAG) -o $(NAME)

clean:
	rm -f $(OBJS)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean