# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mariana <mariana@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/30 20:55:35 by mariana           #+#    #+#              #
#    Updated: 2022/08/22 22:22:36 by mariana          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# INC=%%%%
# INCLIB=$(INC)/../lib
# UNAME := $(shell uname)
# CFLAGS= -I$(INC) -O3 -I.. -g
# NAME = fractal.a
# SRC = src/main.c \
# 			src/ft_strcmp.c
# OBJ = $(SRC:%.c=%.o)
# LFLAGS = -L.. -lmlx -L$(INCLIB) -lXext -lX11 -lm

# ifeq ($(UNAME), Darwin)
# 	# mac
# 	CC = clang
# else ifeq ($(UNAME), FreeBSD)
# 	# FreeBSD
# 	CC = clang
# else
# 	#Linux and others...
# 	CC	= gcc
# 	LFLAGS += -lbsd
# endif

# all: $(NAME)

# $(NAME): $(OBJ)
# 	$(CC) -o $(NAME) $(OBJ) $(LFLAGS)
	
# # 
# NAME = fractal.a

# UNAME := $(shell uname)

# INC=%%%%
# INCLIB=$(INC)/../lib
# LFLAGS = -L.. -lmlx -L$(INCLIB) -lXext -lX11 -lm
# ifeq ($(UNAME), Darwin)
# 	# mac
# 	CC = clang
# 	LFLAGS += --framework OpenGL -framework AppKit
# else ifeq ($(UNAME), FreeBSD)
# 	# FreeBSD
# 	CC = clang
# else
# 	#Linux and others...
# 	CC	= gcc
# 	LFLAGS += -lbsd
# endif

# LIBFT_DIR = libft/
# LIBFT = $(LIBFT_DIR)/libft.a

# SRC_DIR = src/
# SRC = ft_strcmp.c \
# 			ft_get_set.c

# OBJ_DIR = obj/
# OBJ = $(SRC:%.c=$(OBJ_DIR)%.o)

# vpath %.c $(SRC_DIR)

# CFLAGS= -Wall -Wextra -Werror -I$(INC) -O3 -I.. -g

# MY_LIB_PATH = ../../my_lib/libft.a

# all: $(NAME)

# $(NAME): $(OBJ)
# 	$(MAKE) all -C $(LIBFT_DIR)
# 	cp $(LIBFT) $(NAME)
# 	ar -rc $(NAME) $(OBJ)

# $(OBJ_DIR)%.o: %.c | $(OBJ_DIR)
# 	$(CC) $(CFLAGS) -I./include -c $< -o $@ $(LFLAGS)

# # $(CC) -o $(NAME) $(OBJ) $(LFLAGS)
# # $(CC) -I ../include -c $< -o $@ $(LFLAGS)

# $(OBJ_DIR):
# 	mkdir -p $@
	
# clean:
# 	$(MAKE) -C $(LIBFT_DIR) clean
# 	rm -rf $(OBJ_DIR)

# fclean: clean
# 	$(MAKE) -C $(LIBFT_DIR) fclean
# 	rm -f $(NAME)
# # 	rm a.out
# # # should delete a.out?????????????????????

# re: fclean all

# .PHONY: all clean fclean re

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

compi: #make compu name=bla
	@clang -Wall -Wextra -Werror ./src/main.c $(MY_LIB_PATH) $(NAME) -lX11 -lXext -lmlx && ./a.out
# @gcc $(LFLAGS) src/main.c fractal.a 
# @gcc -lmlx -L/usr/local/include/ -lXext -lX11 -lm obj/main.o fractal.a 
# @./a.out ${name}

test:
	@clang -Wall -Wextra -Werror  ./src/main.c -lX11 -lXext -lmlx && ./a.out

out:
	@./a.out

run:
	gcc -c -Wall -Werror -Wextra ./src/main.c -lX11 -lXext -lmlx -I ./include/
	gcc -o main main.o
