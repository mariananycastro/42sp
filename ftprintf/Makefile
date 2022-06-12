NAME		= libftprintf.a

LIBFT_DIR	= ./libft/
LIBFT 		= $(LIBFT_DIR)/libft.a

SRC_DIR		= ./src/
SRC			=	$(SRC_DIR)/*.c

OBJ			= $(SRC:.c=.o)

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC)
	$(MAKE) bonus -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)
	$(CC) $(CFLAGS) -c $(SRC) -I ./include/
	mv *.o ./src/
	ar -rc $(NAME) $(OBJ)

clean:
	rm -f $(LIBFT_DIR)*.o
	rm -f $(SRC_DIR)*.o

fclean: clean
	rm -f $(LIBFT_DIR)*.a
	rm -f $(NAME)

re: fclean all

compi: fclean
	rm -f a.out
	$(MAKE) bonus -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)
	$(CC) -c $(SRC) $(SRC_DIR)main.c -I ./include/
	mv *.o ./src/
	ar -rc $(NAME) $(OBJ)
	gcc $(SRC_DIR)main.o libftprintf.a && ./a.out  

.PHONY: all clean fclean re