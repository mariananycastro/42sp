# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcastro <mariananycastro@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 00:42:15 by mcastro           #+#    #+#              #
#    Updated: 2022/03/28 00:42:16 by mcastro          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
PATH_SRC = ./srcs
HEADER = ./includes/
FILES = $(PATH_SRC)/ft_putchar.c $(PATH_SRC)/ft_putstr.c $(PATH_SRC)/ft_strcmp.c \
		$(PATH_SRC)/ft_strlen.c $(PATH_SRC)/ft_swap.c
OBJ = ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(FILES) -I ${HEADER}
	ar -rc $(NAME) $(OBJ)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
