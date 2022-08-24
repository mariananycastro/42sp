# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mariana <mariana@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/30 20:55:35 by mariana           #+#    #+#              #
#    Updated: 2022/08/24 11:51:00 by mariana          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES_PATH = ./src/
FILES_NAMES = handle_destroy_window.c handle_keyrelease.c ft_create_map.c \
							ft_validate_map.c ft_check_map_titles.c ft_is_wall.c \
							ft_validate_extension.c ft_set_map_matrix.c ft_get_map_size.c \
							render.c ft_create_imgs.c ft_destroy.c ft_exit.c
FILES = $(FILES_PATH)handle_destroy_window.c \
				$(FILES_PATH)handle_keyrelease.c \
				$(FILES_PATH)ft_create_map.c \
				$(FILES_PATH)ft_validate_map.c \
				$(FILES_PATH)ft_check_map_titles.c \
				$(FILES_PATH)ft_is_wall.c \
				$(FILES_PATH)ft_validate_extension.c \
				$(FILES_PATH)ft_set_map_matrix.c \
				$(FILES_PATH)ft_get_map_size.c \
				$(FILES_PATH)render.c \
				$(FILES_PATH)ft_create_imgs.c \
				$(FILES_PATH)ft_destroy.c \
				$(FILES_PATH)ft_exit.c
FILES_O 	= $(FILES_NAMES:.c=.o)
NAME = so_long.a
MY_LIB_PATH = ../../my_lib/libft.a

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(FILES) -I .
	ar -rc $(NAME) $(FILES_O)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

compi:
	@clang -Wall -Wextra -Werror ./src/main.c $(MY_LIB_PATH) $(NAME) -lX11 -lXext -lmlx && ./a.out
# @gcc $(LFLAGS) src/main.c so_long.a 
# @gcc -lmlx -L/usr/local/include/ -lXext -lX11 -lm obj/main.o so_long.a 
# @./a.out ${name}

test:
	@clang -Wall -Wextra -Werror  ./src/main.c -lX11 -lXext -lmlx && ./a.out

out:
	@./a.out

run:
	gcc -c -Wall -Werror -Wextra ./src/main.c -lX11 -lXext -lmlx -I ./include/
	gcc -o main main.o
