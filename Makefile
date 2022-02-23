# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mprigent <mprigent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/12 15:13:21 by mprigent          #+#    #+#              #
#    Updated: 2021/10/14 17:35:42 by mprigent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

MLX			=	libmlx.a

SRCS			=	srcs/ft_display.c \
					srcs/ft_init_window.c \
					srcs/ft_keyboard.c \
					srcs/ft_load_text.c \
					srcs/ft_move_player.c \
					srcs/ft_print_err.c \
					srcs/ft_render.c \
					GNL/get_next_line.c \
					parsing/ft_ber_check.c \
					parsing/ft_check_map.c \
					parsing/ft_check_walls.c \
					parsing/ft_check.c \
					parsing/ft_exit_free.c \
					parsing/ft_free_map.c \
					parsing/ft_get_coord.c \
					parsing/ft_gnl_line.c \
					parsing/ft_init_var.c \
					parsing/ft_malloc_map.c \
					parsing/ft_parsing.c \
					parsing/ft_stock_map.c \
					libft/ft_putchar.c \
					libft/ft_putendl_fd.c \
					libft/ft_putnbr.c \
					libft/ft_putstr.c \
					libft/ft_strlen.c \
					so_long.c \
					
CC			=	clang

CFLAGS		=	-Wall -Wextra -Werror

UNAME		:=	$(shell uname)

ifeq ($(UNAME), Darwin)
$(NAME):
			@echo "\033[33m[Compilation of so_long...]"
			@ $(MAKE) -C mlx all >/dev/null 2>&1
			@ cp ./mlx/$(MLX) .
			@$(CC) $(CFLAGS) -g3 -Ofast -o $(NAME) -Imlx $(SRCS) -g -fsanitize=address -Lmlx -lmlx -lm -framework OpenGL -framework AppKit
			@echo "\033[32m[ ./so_long created ]"
endif

ifeq ($(UNAME), Linux)
$(NAME):
			@echo "\033[31;1mCompiling for Linux...\033[0m"
			@chmod 777 mlx_linux/configure
			@ $(MAKE) -C mlx_linux all
			$(CC) $(CFLAGS) -g3 -o $(NAME) $(SRCS) -Imlx_linux -Lmlx_linux -lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm
			@echo "\033[32m[ ./so_long created ]"
endif

all:		$(NAME)

ifeq ($(UNAME), Darwin)
clean:
			@ echo "\033[31m[Remove last version...]"
			@ $(MAKE) -C mlx clean
endif

ifeq ($(UNAME), Linux)
clean:
			@ echo "\033[31m[Remove last version...]"
			@ $(MAKE) -C mlx_linux clean 
endif

ifeq ($(UNAME), Darwin)
fclean:		clean
			@ rm $(MLX)
			@ rm so_long >/dev/null 2>&1
			@ rm -rf so_long.dSYM
endif

ifeq ($(UNAME), Linux)
fclean:		clean
			@ rm so_long >/dev/null 2>&1
endif

re:			fclean all

.PHONY:		$(NAME) all test clean fclean re
