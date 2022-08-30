# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mariana <mariana@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/30 20:55:35 by mariana           #+#    #+#              #
#    Updated: 2022/08/29 23:52:24 by mariana          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES_PATH = ./src/
FILES_NAMES = handle_destroy_window.c handle_keyrelease.c ft_create_map.c \
							ft_validate_extension.c ft_set_map_matrix.c ft_get_map_size.c \
							render.c ft_create_imgs.c ft_destroy_display.c ft_exit.c \
							ft_check_map_tiles.c ft_message.c \
							ft_destroy_imgs.c ft_error_message.c ft_destroy_matrix.c \
							ft_create_img.c ft_validate_map.c ft_thanks_msg.c
FILES = $(FILES_PATH)handle_destroy_window.c \
				$(FILES_PATH)handle_keyrelease.c \
				$(FILES_PATH)ft_create_map.c \
				$(FILES_PATH)ft_validate_map.c \
				$(FILES_PATH)ft_validate_extension.c \
				$(FILES_PATH)ft_set_map_matrix.c \
				$(FILES_PATH)ft_get_map_size.c \
				$(FILES_PATH)render.c \
				$(FILES_PATH)ft_create_imgs.c \
				$(FILES_PATH)ft_destroy_display.c \
				$(FILES_PATH)ft_exit.c \
				$(FILES_PATH)ft_check_map_tiles.c \
				$(FILES_PATH)ft_message.c \
				$(FILES_PATH)ft_destroy_imgs.c \
				$(FILES_PATH)ft_error_message.c \
				$(FILES_PATH)ft_destroy_matrix.c \
				$(FILES_PATH)ft_create_img.c \
				$(FILES_PATH)ft_thanks_msg.c
FILES_O 	= $(FILES_NAMES:.c=.o)
NAME = so_long.a
MY_LIB_PATH = ../../my_lib/libft.a
MY_LIB_PATH_HEADER = ../../my_lib/libft.h

all: $(NAME)

$(NAME):
	clang -Wall -Wextra -Werror -c $(FILES) -I .
	ar -rc $(NAME) $(FILES_O)
	clang -Wall -Wextra -Werror -g ./src/main.c $(MY_LIB_PATH) $(NAME) -lX11 -lXext -lmlx 


# O -L aponta apenas o caminho da lib, não ela em si. O -l que aponta o arquivo da lib. 
# E o interessante é que o o -l já presume que a lib começa com o prefixo "lib" e termina com o sufixo ".a",
#  então você pode escrever o -l assim para a libft: -lft
# Exemplos de complilação que funcionaram aqui:
# gcc test.c -I ./include/ -L . -lft -o test.out
# gcc test.c -I ./include/ libft.a -o test.out
# gcc ./src/main.c -I so_long.h  ../../my_lib/libft.h ../../my_lib/libft.a -o test.out -lX11 -lXext -lmlx 

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

run:
# @valgrind --leak-check=full --show-reachable=yes --track-origins=yes --show-leak-kinds=all ./a.out ./maps/map1.ber
# @valgrind --leak-check=full --show-reachable=yes --track-origins=yes --show-leak-kinds=all ./a.out ./maps/map2.ber
# @valgrind --leak-check=full --show-reachable=yes --track-origins=yes --show-leak-kinds=all ./a.out ./maps/map3.ber
	@valgrind --leak-check=full --show-reachable=yes --track-origins=yes --show-leak-kinds=all ./a.out ./maps/map_with_enemy.ber

# empty first line - not rec ok
# @valgrind --leak-check=full --show-reachable=yes --track-origins=yes --show-leak-kinds=all ./a.out ./maps/empty.ber

# missing caracter - invalid map tittle ok
# @valgrind --leak-check=full --show-reachable=yes --track-origins=yes --show-leak-kinds=all ./a.out ./maps/missing_title.ber

# missing wall - invalid map tittle ok
# @valgrind --leak-check=full --show-reachable=yes --track-origins=yes --show-leak-kinds=all ./a.out ./maps/no_wall.ber

# - not rec ok
# @valgrind --leak-check=full --show-reachable=yes --track-origins=yes --show-leak-kinds=all ./a.out ./maps/not_rec1.ber

# - invalid map title ok
# @valgrind --leak-check=full --show-reachable=yes --track-origins=yes ./a.out ./maps/not_rec2.ber

# not square, with space in the end - invalid map title ok
# @valgrind --leak-check=full --show-reachable=yes --track-origins=yes ./a.out ./maps/not_rec2.ber

# not right extention ok
# @valgrind --leak-check=full --show-reachable=yes --track-origins=yes ./a.out ./maps/not_ber.txt

# file does not exist - invalid map titles ok
# @valgrind --leak-check=full --show-reachable=yes --track-origins=yes ./a.out ./maps/bolinha.ber

