# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mariana <mariana@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/30 20:55:25 by mariana           #+#    #+#              #
#    Updated: 2022/07/30 20:55:27 by mariana          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC 		= ft_atoi.c \
					ft_bzero.c \
					ft_calloc.c \
					ft_decimal.c \
					ft_isalnum.c \
					ft_isalpha.c \
					ft_isascii.c \
					ft_isdigit.c \
					ft_islower.c \
					ft_isprint.c \
					ft_isspace.c \
					ft_isupper.c \
					ft_itoa.c \
					ft_lstadd_back.c \
					ft_lstadd_front.c \
					ft_lstclear.c \
					ft_lstdelone.c \
					ft_lstiter.c \
					ft_lstlast.c	\
					ft_lstmap.c \
					ft_lstnew.c \
					ft_lstsize.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_memcpy.c \
					ft_memmove.c \
					ft_memset.c \
					ft_pointer.c \
					ft_printf.c \
					ft_putchar_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c \
					ft_putstr_fd.c \
					ft_split.c \
					ft_str_has_char.c \
					ft_strappend.c \
					ft_strchr.c \
					ft_strdup.c \
					ft_string.c \
					ft_striteri.c \
					ft_strjoin.c \
					ft_strlcat.c \
					ft_strlcpy.c \
					ft_strlen.c \
					ft_strmapi.c \
					ft_strncmp.c \
					ft_strnstr.c \
					ft_strrchr.c \
					ft_strtrim.c \
					ft_substr.c\
					ft_to_base.c \
					ft_tolower.c \
					ft_toupper.c \
					ft_get_next_line.c

NAME = libft.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)

%.o:	%.c
		gcc -Wall -Wextra -Werror -I ../include -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
