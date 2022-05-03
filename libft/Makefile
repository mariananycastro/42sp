MANDATORY 		= ft_atoi.c ft_isascii.c ft_isupper.c ft_memset.c ft_split.c ft_strlcat.c ft_strnstr.c \
									ft_toupper.c ft_bzero.c ft_isdigit.c ft_itoa.c ft_memchr.c ft_putchar_fd.c ft_strchr.c \
									ft_strlcpy.c ft_strrchr.c ft_calloc.c ft_islower.c ft_memcmp.c ft_putendl_fd.c ft_strdup.c \
									ft_strlen.c ft_strtrim.c ft_isalnum.c ft_isprint.c ft_memcpy.c ft_putnbr_fd.c ft_striteri.c \
									ft_strmapi.c ft_substr.c ft_isalpha.c ft_isspace.c ft_memmove.c ft_putstr_fd.c ft_strjoin.c \
									ft_strncmp.c ft_tolower.c
MANDATORY_O 	= $(MANDATORY:.c=.o)
BONUS 				= ft_lstdelone.c ft_lstsize.c ft_lstiter.c ft_lstadd_back.c ft_lstlast.c	\
									ft_lstadd_front.c ft_lstmap.c ft_lstclear.c ft_lstnew.c
BONUS_O				= $(BONUS:.c=.o)

NAME = libft.a

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(MANDATORY) -I .
	ar -rc $(NAME) $(MANDATORY_O)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

bonus:
	gcc -Wall -Wextra -Werror -c $(MANDATORY) $(BONUS) -I .
	ar -rc $(NAME) $(MANDATORY_0) $(BONUS_O)
