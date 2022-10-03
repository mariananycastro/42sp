# libft
LIBRARY_PATH		= ./libft
LIB_NAME 				= libft.a
LIBFT_FILE 		 	= $(LIBRARY_PATH)/libft.a

CC         			= clang
CFLAGS     			= -Wall -Wextra -Werror
NAME						= pipex
FILES_NAMES			= ft_error.c ft_set_stdout.c ft_check_error.c ft_error_fork.c \
									ft_error_fork.c ft_close_fd.c ft_exec_p1.c ft_set_stdin.c \
									ft_exec_cmd.c ft_set_stderr.c ft_exec_p2.c

SRC_DIR 	= src/
OBJ_DIR 	= obj/
OBJ 			= $(FILES_NAMES:%.c=$(OBJ_DIR)%.o)
NAME_LIB 	= pipex.a

INCLUDE_PATH 	= include
MAIN_FILE 		= $(SRC_DIR)main.c

vpath %.c $(SRC_DIR)

all: $(NAME)

# $(NAME): $(LIB_NAME)
# # $(CC) $(CFLAGS) -g main.c -o $(NAME)
# 	@$(CC) $(CFLAGS) -g main.c -I $(LIBRARY_PATH) $(LIBFT_FILE) -o $(NAME)


$(NAME): $(NAME_LIB)
	@$(CC) $(CFLAGS) -g $(MAIN_FILE) -I $(INCLUDE_PATH) -I $(LIBRARY_PATH) $(NAME_LIB) $(LIBFT_FILE) -o $(NAME)

$(NAME_LIB): $(LIB_NAME) $(OBJ)
	@ar -rc $(NAME_LIB) $(OBJ)

$(OBJ_DIR)%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -I $(INCLUDE_PATH) -I $(LIBRARY_PATH) -o $@ 

$(OBJ_DIR):
	@mkdir -p $@

run:
# @valgrind -s --leak-check=full --show-reachable=yes --track-origins=yes --show-leak-kinds=all ./pipex file " ls  -l " "wc -l" file2
# @./pipex file1 "ls -l" "wc -z" file2
	@./pipex file1 "ls -l" "wc -l" file2
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

clean:
	rm -f $(OBJ_DIR)*.o

fclean:
	@rm -f $(NAME)

re: fclean all run

# libft
$(LIB_NAME):
	@$(MAKE) all -C $(LIBRARY_PATH)
	@cp $(LIBFT_FILE) $(LIB_NAME)

libclean:
	@$(MAKE) clean -C $(LIBRARY_PATH)

libfclean:
	@$(MAKE) fclean -C $(LIBRARY_PATH)
	@rm -f $(LIB_NAME)

libre:
	@$(MAKE) re -C $(LIBRARY_PATH)
