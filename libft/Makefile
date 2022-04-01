all: libft

libft:
	gcc -Wall -Wextra -Werror -c *.c -I .
	ar -rc libft.a *.o

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f libft.a

re: fclean all
