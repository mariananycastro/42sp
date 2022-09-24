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
	@$(CC) -g main.c -I $(LIBRARY_PATH) $(LIBFT_FILE) -o $(NAME)

run:
	@./pipex file1 " ls  -l " "wc -l" file2

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
