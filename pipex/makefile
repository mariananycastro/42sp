# libft
LIBRARY_PATH		= ./libft
LIB_NAME 				= libft.a
LIBFT_FILE 		 	= $(LIBRARY_PATH)/libft.a

CC         			= clang
CFLAGS     			= -Wall -Wextra -Werror
NAME						= pipex

all: $(NAME)

$(NAME): $(LIB_NAME)
# $(CC) $(CFLAGS) -g main.c -o $(NAME)
	@$(CC) $(CFLAGS) -g main.c -I $(LIBRARY_PATH) $(LIBFT_FILE) -o $(NAME)

run:
# @valgrind -s --leak-check=full --show-reachable=yes --track-origins=yes --show-leak-kinds=all ./pipex file " ls  -l " "wc -l" file2
# @./pipex file1 "ls -l" "wc -z" file2
# @./pipex file1 "ls -z" "wc -l" file2
# @./pipex file1 "ls -z" "wc -z" file2
# @./pipex file1 "ls -l" "wc -l" file2
# @./pipex file1 "grep a1" "wc -w" file2

ex:
# @< file1 ls -l | wc -l > file2
# @< file1 ls -l | wc -z > file2
# @< file1 ls -z | wc -l > file2
# @< file1 ls -z | wc -z > file2
# @< file1 grep a1 | wc -l > file2
# @< file1 grep a1 | wc -z > file2
# @< file1 grep | wc -l > file2
# @< file1 grep | wc -z > file2

fclean:
	@rm -f pipex

re: fclean all run

# libft
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
