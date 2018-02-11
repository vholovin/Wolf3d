# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vholovin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/09 11:36:50 by vholovin          #+#    #+#              #
#    Updated: 2017/08/08 18:40:59 by vholovin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= wolf3d
NAME_dSYM	= $(NAME:=.dSYM)

CC			= gcc
FLAG		= -Wall -Wextra -Werror -pedantic
FRAMEWORK	= -lmlx -framework OpenGL -framework AppKit
LOCAL		= -I minilibX -g -L minilibX
LIBFT		= libft/libft.a

SRC			= src/main.c		\
			src/init_wolf.c		\
			src/init_rays.c		\
			src/open_map.c		\
			src/error.c			\
			src/ft_free.c		\
			src/init_texture.c	\
			src/expose_hook.c	\
			src/get_color.c		\
			src/ray_casting.c	\
			src/set_texture.c	\
			src/key_hook.c		\
			src/esc.c			\
			src/move_rotate.c	\
			src/fps.c			\
			src/tutorial.c

OBJ			= $(patsubst src/%.c,obj/%.o,$(SRC))
.SILENT:

all: $(NAME)

obj/%.o: src/%.c
	mkdir -p obj
	$(CC) $(FLAG) -c $< -o $@
	printf '\033[31m ✔  %s\n\033[0m' "$<"

$(NAME): $(OBJ)
	make -C libft/
	$(CC) $(FLAG) $(LIBFT) $(LOCAL) $(FRAMEWORK) $(OBJ) -o $(NAME)
	printf '\033[32m ✔  %s\n\033[0m' "Create Wolf3D"

clean:
	make -C libft/ clean
	rm -f $(OBJ)
	rm -f $(NAME_dSYM)
	printf '\033[33m ✔  %s\n\033[0m' "Clean Wolf3D"

fclean: clean
	make -C libft/ fclean
	rm -rf obj
	rm -f $(NAME)
	printf '\033[33m ✔  %s\n\033[0m' "Fclean Wolf3D"

re: fclean all

all: $(NAME)
.PHONY: clean fclean re all
