NAME = get_next_level.a

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -D BUFFER_SIZE=${BUFFER_SIZE} -c *.c -I .
	ar -rc $(NAME) *.o

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all