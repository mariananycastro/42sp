# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mariana <mariana@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/30 20:55:35 by mariana           #+#    #+#              #
#    Updated: 2022/08/21 10:20:55 by mariana          ###   ########.fr        #
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
NAME = fractal.a

UNAME := $(shell uname)

INC=%%%%
INCLIB=$(INC)/../lib
LFLAGS = -L.. -lmlx -L$(INCLIB) -lXext -lX11 -lm
ifeq ($(UNAME), Darwin)
	# mac
	CC = clang
	LFLAGS += --framework OpenGL -framework AppKit
else ifeq ($(UNAME), FreeBSD)
	# FreeBSD
	CC = clang
else
	#Linux and others...
	CC	= gcc
	LFLAGS += -lbsd
endif

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR = src/
SRC = ft_strcmp.c \
			ft_get_set.c

OBJ_DIR = obj/
OBJ = $(SRC:%.c=$(OBJ_DIR)%.o)

vpath %.c $(SRC_DIR)

CFLAGS= -Wall -Wextra -Werror -I$(INC) -O3 -I.. -g

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) all -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)
	ar -rc $(NAME) $(OBJ)

$(OBJ_DIR)%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I./include -c $< -o $@ $(LFLAGS)

# $(CC) -o $(NAME) $(OBJ) $(LFLAGS)
# $(CC) -I ../include -c $< -o $@ $(LFLAGS)

$(OBJ_DIR):
	mkdir -p $@
	
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
# 	rm a.out
# # should delete a.out?????????????????????

re: fclean all

.PHONY: all clean fclean re

compi: #make compu name=bla
	@gcc $(LFLAGS) src/main.c fractal.a 
# @gcc -lmlx -L/usr/local/include/ -lXext -lX11 -lm obj/main.o fractal.a 
# @./a.out ${name}

test:
	@clang -Wall -Wextra -Werror  ./src/$(file) -lX11 -lXext -lmlx && ./a.out
