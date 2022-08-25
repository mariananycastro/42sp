# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mariana <mariana@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/30 20:55:35 by mariana           #+#    #+#              #
#    Updated: 2022/08/25 20:43:25 by mariana          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES_PATH = ./src/
FILES_NAMES = handle_destroy_window.c handle_keyrelease.c ft_create_map.c \
							ft_validate_map.c ft_check_map_titles.c \
							ft_validate_extension.c ft_set_map_matrix.c ft_get_map_size.c \
							render.c ft_create_imgs.c ft_destroy.c ft_exit.c
FILES = $(FILES_PATH)handle_destroy_window.c \
				$(FILES_PATH)handle_keyrelease.c \
				$(FILES_PATH)ft_create_map.c \
				$(FILES_PATH)ft_validate_map.c \
				$(FILES_PATH)ft_check_map_titles.c \
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
	clang -Wall -Wextra -Werror -c $(FILES) -I .
	ar -rc $(NAME) $(FILES_O)
	clang -Wall -Wextra -Werror -g ./src/main.c $(MY_LIB_PATH) $(NAME) -lX11 -lXext -lmlx 

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

run:
# @./a.out ./maps/map1.ber
# @./a.out ./maps/map2.ber
	@valgrind --leak-check=full --show-reachable=yes ./a.out ./maps/map1.ber
# @valgrind --leak-check=full --show-leak-kinds=all ./a.out ./maps/map3.ber

# empty first line - not rec
# @./a.out ./maps/empty.ber

# missing caracter - invalid map tittle
# @./a.out ./maps/missing_title.ber

# missing wall - invalid map tittle
# @./a.out ./maps/no_wall.ber

# - not rec
# @./a.out ./maps/not_rec1.ber

# - invalid map title
# @./a.out ./maps/not_rec2.ber

# not square, with space in the end - invalid map title
# @./a.out ./maps/not_rec2.ber

# not right extention 
# @./a.out ./maps/not_ber.txt

# file does not exist
# @./a.out ./maps/bolinha.ber

