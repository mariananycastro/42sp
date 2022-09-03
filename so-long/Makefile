# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mariana <mariana@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/30 20:55:35 by mariana           #+#    #+#              #
#    Updated: 2022/09/03 16:09:33 by mariana          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC         			= clang
CFLAGS     			= -Wall -Wextra -Werror
NAME       			= so_long.a
LIBRARY_PATH		= ./libft
LIBFT_FILE 		 	= $(LIBRARY_PATH)/libft.a
C_INCLUDE_PATH 	= include
FILES_PATH 			= ./src/
FILES 		 			= $(FILES_PATH)handle_destroy_window.c \
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
						 			$(FILES_PATH)ft_thanks_msg.c \
						 			$(FILES_PATH)ft_create_window.c
FILES_O 	 			= $(FILES:.c=.o)
MAIN 						= ./src/main.c

all: $(NAME)

$(NAME): linklib
	$(CC) $(CFLAGS) -c $(FILES) -I $(C_INCLUDE_PATH) -I $(LIBRARY_PATH)
	mv *.o $(FILES_PATH)
	ar -rc $(NAME) $(FILES_O)

compi:
# $(CC) $(CFLAGS) -g $(MAIN) -I $(C_INCLUDE_PATH) -I $(LIBRARY_PATH) $(NAME) $(LIBFT_FILE) -lmlx -lX11 -lXext 
	gcc $(CFLAGS) -g $(MAIN) -I $(C_INCLUDE_PATH) -I $(LIBRARY_PATH) $(NAME) $(LIBFT_FILE) -lmlx -lX11 -lXext 

clean:
	/bin/rm -f $(FILES_PATH)*.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

linklib:
	$(MAKE) all -C $(LIBRARY_PATH)

libclean:
	$(MAKE) clean -C $(LIBRARY_PATH)

libfclean:
	$(MAKE) fclean -C $(LIBRARY_PATH)

libre:
	$(MAKE) re -C $(LIBRARY_PATH)

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

