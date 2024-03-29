# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mariana <mariana@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/30 20:55:35 by mariana           #+#    #+#              #
#    Updated: 2022/09/05 20:53:39 by mariana          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC         			= clang
CFLAGS     			= -Wall -Wextra -Werror
FILES_NAMES			= handle_destroy_window.c \
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
                  ft_create_window.c \
									ft_create_imgs.c \
									ft_destroy_imgs.c \
									ft_message.c \
									render.c \
									ft_move.c \
									ft_valid_tiles.c

BONUS_FILES_NAMES			= handle_destroy_window_bonus.c \
												handle_keyrelease_bonus.c \
												ft_create_map_bonus.c \
												ft_validate_map_bonus.c \
												ft_validate_extension_bonus.c \
												ft_set_map_matrix_bonus.c \
												ft_get_map_size_bonus.c \
												ft_destroy_display_bonus.c \
												ft_exit_bonus.c \
												ft_check_map_tiles_bonus.c \
												ft_error_message_bonus.c \
												ft_destroy_matrix_bonus.c \
												ft_create_img_bonus.c \
												ft_thanks_msg_bonus.c \
												ft_create_window_bonus.c \
												ft_create_imgs_bonus.c \
												ft_destroy_imgs_bonus.c \
												ft_message_bonus.c \
												render_bonus.c \
												ft_move_bonus.c \
												ft_valid_tiles_bonus.c

SRC_DIR 	= src/
BONUS_DIR = bonus/src/

OBJ_DIR 			= obj/
BONUS_OBJ_DIR = bonus/obj/

OBJ 			= $(FILES_NAMES:%.c=$(OBJ_DIR)%.o)
BONUS_OBJ = $(BONUS_FILES_NAMES:%.c=$(BONUS_OBJ_DIR)%.o)

NAME 				= so_long
NAME_BONUS 	= so_long_bonus

NAME_LIB 				= so_long.a
NAME_BONUS_LIB 	= bonus.a

vpath %.c $(SRC_DIR)
vpath %.c $(BONUS_DIR)

LIBRARY_PATH		= ./libft
LIB_NAME 				= libft.a
LIBFT_FILE 		 	= $(LIBRARY_PATH)/libft.a

INCLUDE_PATH 				= include
BONUS_INCLUDE_PATH 	= bonus/include

MAIN_FILE 			= $(SRC_DIR)main.c
BONUS_FILE 			= $(BONUS_DIR)bonus.c

all: $(NAME)

$(NAME): $(NAME_LIB)
	$(CC) $(CFLAGS) -g $(MAIN_FILE) -I $(INCLUDE_PATH) -I $(LIBRARY_PATH) $(NAME_LIB) $(LIBFT_FILE) -lmlx -lX11 -lXext -o $(NAME)

$(NAME_LIB): $(LIB_NAME) $(OBJ)
		ar -rc $(NAME_LIB) $(OBJ)

$(OBJ_DIR)%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -I $(INCLUDE_PATH) -I $(LIBRARY_PATH) -o $@ 

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -f $(OBJ_DIR)*.o

fclean: clean
	rm -f $(NAME_LIB)
	rm $(NAME)

re: fclean all

$(NAME_BONUS): $(NAME_BONUS_LIB)
	$(CC) $(CFLAGS) -g $(BONUS_FILE) -I $(BONUS_INCLUDE_PATH) -I $(LIBRARY_PATH) $(NAME_BONUS_LIB) $(LIBFT_FILE) -lmlx -lX11 -lXext -o $(NAME_BONUS)

$(NAME_BONUS_LIB): $(LIB_NAME) $(BONUS_OBJ)
	ar -rc $(NAME_BONUS_LIB) $(BONUS_OBJ)

$(BONUS_OBJ_DIR)%.o: %.c | $(BONUS_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -I $(BONUS_INCLUDE_PATH) -I $(LIBRARY_PATH) -o $@ 

$(BONUS_OBJ_DIR):
	mkdir -p $@

bclean:
	rm -f $(BONUS_OBJ_DIR)*.o

bfclean: bclean
	rm -f $(NAME_BONUS)
	rm -f $(NAME_BONUS_LIB)

bre: bfclean all

$(LIB_NAME):
	$(MAKE) all -C $(LIBRARY_PATH)
	cp $(LIBFT_FILE) $(LIB_NAME)

libclean:
	$(MAKE) clean -C $(LIBRARY_PATH)

libfclean:
	$(MAKE) fclean -C $(LIBRARY_PATH)
	rm -f $(LIB_NAME)

libre:
	$(MAKE) re -C $(LIBRARY_PATH)

run: so_long
# @./so_long ./maps/map_with_enemy.ber
# @./so_long ./maps/bolinha.ber
	@./so_long ./maps/map1.ber
#	@./so_long ./maps/map2.ber
# @./so_long ./maps/map3.ber
# @./so_long ./maps/empty.ber
# @./so_long ./maps/missing_tile.ber
# @./so_long ./maps/no_wall.ber
# @./so_long ./maps/not_rec1.ber
# @./so_long ./maps/not_rec2.ber
# @./so_long ./maps/not_rec2.ber
# @./so_long ./maps/not_ber.txt

# @valgrind --leak-check=full --show-reachable=yes --track-origins=yes --show-leak-kinds=all ./so_long ./maps/map1.ber
# @valgrind --leak-check=full --show-reachable=yes --track-origins=yes --show-leak-kinds=all ./so_long ./maps/map2.ber
# @valgrind --leak-check=full --show-reachable=yes --track-origins=yes --show-leak-kinds=all ./so_long ./maps/map3.ber
# @valgrind --leak-check=full --show-reachable=yes --track-origins=yes --show-leak-kinds=all ./so_long ./maps/map_with_enemy_bonus.ber

# empty first line - not rec ok
# @valgrind --leak-check=full --show-reachable=yes --track-origins=yes --show-leak-kinds=all ./so_long ./maps/empty.ber

# missing caracter - invalid map tile ok
# @valgrind --leak-check=full --show-reachable=yes --track-origins=yes --show-leak-kinds=all ./so_long ./maps/missing_tile.ber

# missing wall - invalid map tile ok
# @valgrind --leak-check=full --show-reachable=yes --track-origins=yes --show-leak-kinds=all ./so_long ./maps/no_wall.ber

# - not rec ok
# @valgrind --leak-check=full --show-reachable=yes --track-origins=yes --show-leak-kinds=all ./so_long ./maps/not_rec1.ber

# - invalid map tile ok
# @valgrind --leak-check=full --show-reachable=yes --track-origins=yes ./so_long ./maps/not_rec2.ber

# not square, with space in the end - invalid map tile ok
# @valgrind --leak-check=full --show-reachable=yes --track-origins=yes ./so_long ./maps/not_rec2.ber

# not right extention ok
# @valgrind --leak-check=full --show-reachable=yes --track-origins=yes ./so_long ./maps/not_ber.txt

# file does not exist - invalid map tiles ok
# @valgrind --leak-check=full --show-reachable=yes --track-origins=yes ./so_long ./maps/bolinha.ber
