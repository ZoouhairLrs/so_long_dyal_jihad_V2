# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zlaarous <zlaarous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/05 21:50:15 by zlaarous          #+#    #+#              #
#    Updated: 2023/04/09 19:48:03 by zlaarous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long
BONUS_NAME		= so_long_bonus

SRCS		= 		./mendatory/main.c \
					./get_next_line/get_next_line.c \
					./get_next_line/get_next_line_utils.c \
					./mendatory/init_stacks.c\
					./mendatory/ft_split.c \
					./mendatory/Tools.c \
					./mendatory/create_image.c \
					./mendatory/setting_img.c \
					./mendatory/check_map.c \
					./mendatory/ft_message.c \
					./mendatory/ft_putstr.c \
					./mendatory/check_ber.c \
					./mendatory/ft_hook.c \
					./mendatory/closing_pross.c \
					./mendatory/move_up.c \
					./mendatory/move_down.c \
					./mendatory/move_left.c \
					./mendatory/move_right.c \
					./mendatory/back_track.c \
					./mendatory/ft_putnbr.c \
					./mendatory/ft_putchar.c \
					./mendatory/ft_itoa.c \

SRCS_BONUS		= 		./bonus/so_long_bonus.c \
						./get_next_line/get_next_line.c \
						./get_next_line/get_next_line_utils.c \
						./bonus/init_stacks_bonus.c\
						./bonus/ft_split_bonus.c \
						./bonus/Tools_bonus.c \
						./bonus/create_image_bonus.c \
						./bonus/setting_img_bonus.c \
						./bonus/check_map_bonus.c \
						./bonus/ft_message_bonus.c \
						./bonus/ft_putstr_bonus.c \
						./bonus/check_ber_bonus.c \
						./bonus/ft_hook_bonus.c \
						./bonus/closing_pross_bonus.c \
						./bonus/move_up_bonus.c \
						./bonus/move_down_bonus.c \
						./bonus/move_left_bonus.c \
						./bonus/move_right_bonus.c \
						./bonus/back_track_bonus.c \
						./bonus/ft_putnbr_bonus.c \
						./bonus/ft_putchar_bonus.c \
						./bonus/ft_itoa_bonus.c \

INCLUDE 	= mendatory/so_lonh.h

INCLUDE_BONUS = mendatory/so_long_bonus.h

OBJS		= $(SRCS:.c=.o)
OBJS_BONUS		= $(SRCS_BONUS:.c=.o)

FLAG = -Wall -Wextra -Werror

SUPER_FLAG =  -I /usr/X11/include -l mlx -framework OpenGL -framework AppKit

%.o: %.c $(INCLUDE)
	$(CC) $(FLAG) -Imlx -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(SUPER_FLAG) -o $(NAME)
	
bonus : $(BONUS_NAME)

$(BONUS_NAME): $(OBJS_BONUS)
	$(CC) $(OBJS_BONUS) $(SUPER_FLAG) -o $(BONUS_NAME)
	
all: $(NAME)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	
fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all re clean fclean