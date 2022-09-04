# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mariana <mariana@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/30 20:55:35 by mariana           #+#    #+#              #
#    Updated: 2022/09/04 17:23:16 by mariana          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC         			= clang
CFLAGS     			= -Wall -Wextra -Werror
NAME       			= so_long.a
NAME_BONUS      = so_long_bonus.a
LIBRARY_PATH		= ./libft
LIBFT_FILE 		 	= $(LIBRARY_PATH)/libft.a
C_INCLUDE_PATH 	= include
BONUS_INCLUDE_PATH 	= bonus
FILES_PATH 			= ./src/
BONUS_PATH 			= ./bonus/

BOLINHA 		 			= handle_destroy_window.c \
						 			handle_keyrelease.c \
						 			ft_create_map.c \
						 			ft_validate_map.c \
						 			ft_validate_extension.c \
						 			ft_set_map_matrix.c \
						 			ft_get_map_size.c \
						 			ft_destroy_display.c \
						 			ft_exit.c \
						 			ft_check_map_tiles.c \
						 			ft_error_message.c \
						 			ft_destroy_matrix.c \
						 			ft_create_img.c \
						 			ft_thanks_msg.c \
                  ft_create_window.c

FILES 		 			= $(FILES_PATH)handle_destroy_window.c \
						 			$(FILES_PATH)handle_keyrelease.c \
						 			$(FILES_PATH)ft_create_map.c \
						 			$(FILES_PATH)ft_validate_map.c \
						 			$(FILES_PATH)ft_validate_extension.c \
						 			$(FILES_PATH)ft_set_map_matrix.c \
						 			$(FILES_PATH)ft_get_map_size.c \
						 			$(FILES_PATH)ft_destroy_display.c \
						 			$(FILES_PATH)ft_exit.c \
						 			$(FILES_PATH)ft_check_map_tiles.c \
						 			$(FILES_PATH)ft_error_message.c \
						 			$(FILES_PATH)ft_destroy_matrix.c \
						 			$(FILES_PATH)ft_create_img.c \
						 			$(FILES_PATH)ft_thanks_msg.c \
                  $(FILES_PATH)ft_create_window.c

M_FILE 					=	$(FILES_PATH)ft_create_imgs.c \
									$(FILES_PATH)ft_destroy_imgs.c \
									$(FILES_PATH)ft_message.c \
									$(FILES_PATH)render.c \
									$(FILES_PATH)ft_move.c \
									$(FILES_PATH)ft_valid_tiles.c

B_FILE 					= $(BONUS_PATH)ft_create_imgs.c \
									$(BONUS_PATH)ft_destroy_imgs.c \
									$(BONUS_PATH)ft_message.c \
									$(BONUS_PATH)render.c \
									$(BONUS_PATH)ft_move.c \
									$(BONUS_PATH)ft_valid_tiles.c

M_FILE_O 				= $(FILES_PATH)*.o
B_FILE_O 				= $(BONUS_PATH)*.o

MAIN_FILE 			= $(FILES_PATH)main.c
BONUS_FILE 			= $(BONUS_PATH)bonus.c

all: $(NAME)

$(NAME): linklib
	$(CC) $(CFLAGS) -c $(FILES) $(M_FILE) -I $(C_INCLUDE_PATH) -I $(LIBRARY_PATH)
	mv *.o $(FILES_PATH)
	ar -rc $(NAME) $(M_FILE_O)

clean:
	/bin/rm -f $(FILES_PATH)*.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

mcompi:
	$(CC) $(CFLAGS) -g $(MAIN_FILE) -I $(C_INCLUDE_PATH) -I $(LIBRARY_PATH) $(NAME) $(LIBFT_FILE) -lmlx -lX11 -lXext 
# gcc $(CFLAGS) -g $(MAIN_FILE) -I $(C_INCLUDE_PATH) -I $(LIBRARY_PATH) $(NAME) $(LIBFT_FILE) -lmlx -lX11 -lXext 

bonus: linklib
	$(CC) $(CFLAGS) -c $(FILES) $(B_FILE) -I $(BONUS_INCLUDE_PATH) -I $(LIBRARY_PATH)
	mv *.o $(BONUS_PATH)
	ar -rc $(NAME_BONUS) $(B_FILE_O)

bcompi:
	$(CC) $(CFLAGS) -g $(BONUS_FILE) -I $(BONUS_INCLUDE_PATH) -I $(LIBRARY_PATH) $(NAME_BONUS) $(LIBFT_FILE) -lmlx -lX11 -lXext 

bclean:
	/bin/rm -f $(BONUS_PATH)*.o

bfclean: bclean
	/bin/rm -f $(NAME_BONUS)

bre: bfclean all

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

