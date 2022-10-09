LIBRARY 				= libft.a
LIBRARY_PATH		= ./libft
LIBFT_FILE 		 	= $(LIBRARY_PATH)/libft.a

CC         			= clang
CFLAGS     			= -Wall -Wextra -Werror
NAME						= pipex
FILES_NAMES			= ft_check_error.c ft_close_fd.c ft_error.c ft_error_fork.c \
									ft_exec_cmd.c  ft_exec_p1.c ft_exec_p2.c  ft_set_stdout.c \
									ft_set_stdin.c

OBJ_DIR 	= obj/
OBJ 			= $(FILES_NAMES:%.c=$(OBJ_DIR)%.o)
LIST 			= pipex.a

INCLUDE_PATH 	= include
MAIN_FILE 		= $(addprefix src/, main.c)

SRC_DIR 	= src/
vpath %.c $(SRC_DIR)

all: $(NAME)

$(NAME): $(LIST)
	@$(CC) $(CFLAGS) -g $(MAIN_FILE) -I $(INCLUDE_PATH) -I $(LIBRARY_PATH) $(LIST) $(LIBFT_FILE) -o $(NAME)

$(LIST): $(LIBRARY) $(OBJ)
	@ar -rc $(LIST) $(OBJ)

$(OBJ_DIR)%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -I $(INCLUDE_PATH) -I $(LIBRARY_PATH) -o $@ 

$(OBJ_DIR):
	@mkdir -p $@

run:
# @valgrind -s --leak-check=full --show-reachable=yes --track-origins=yes --show-leak-kinds=all ./pipex file1 " ls  -l " "wc -l" file2
# @./pipex no_file "ls -l" "wc -l" file2
# @./pipex file1 "ls  -l " "wc -l" no_file
# @./pipex file1 " ls  -l " "wc -l" file2
# @./pipex file1 "ls -l" "wc -l" file2
# @./pipex file1 "ls -l" "wc -z" file2
# @./pipex file1 "ls -z" "wc -z" file2
# @./pipex file1 "ls -z" "wc -l" file2
# @./pipex file1 "grep a1" "wc -w" file2
# @./pipex file1 "grep a1" "wc -z" file2
# @./pipex file1 "grep" "wc -l" file2
# @./pipex file1 "grep" "wc -z" file2

ex:
# @< no_file ls -l | wc -l > file2
# @< file1 ls -l | wc -l > no_file
# @< file1 ls -l | wc -l > file2
# @< file1 ls -l | wc -z > file2
# @< file1 ls -z | wc -z > file2
# @< file1 ls -z | wc -l > file2
# @< file1 grep a1 | wc -w > file2
# @< file1 grep a1 | wc -z > file2
# @< file1 grep | wc -l > file2
# @< file1 grep | wc -z > file2

clean:
	@rm -f $(OBJ_DIR)*.o

fclean: clean
	@rm -f $(NAME)

re: fclean all run

# libft
$(LIBRARY):
	@$(MAKE) all -C $(LIBRARY_PATH)
	@cp $(LIBFT_FILE) $(LIBRARY)

libclean:
	@$(MAKE) clean -C $(LIBRARY_PATH)

libfclean:
	@$(MAKE) fclean -C $(LIBRARY_PATH)
	@rm -f $(LIBRARY)

libre:
	@$(MAKE) re -C $(LIBRARY_PATH)
