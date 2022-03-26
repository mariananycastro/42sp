NAME = ft_display_file
SRC = ft_display_file.c

all: $(NAME)

$(NAME):
	gcc -c -Wall -Werror -Wextra $(NAME).c
	gcc -o $(NAME) $(NAME).o -I.

clean:
	/bin/rm -f $(NAME).o

fclean: clean
	/bin/rm -f $(NAME)
