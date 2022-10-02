/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 17:00:04 by mariana           #+#    #+#             */
/*   Updated: 2022/10/02 17:11:41 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close_fd(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}

void	ft_check_error(char *message)
{
	if (errno != 0)
	{
		perror(message);
		exit(0);
	}
}

void	ft_set_stdout(char *file2)
{
	int		outfile;

	outfile = open(file2, O_WRONLY); // ou criar arquivo
	ft_check_error("Error File stdout");
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
}

void	ft_error(char *file2, char *message)
{
	ft_set_stdout(file2);
	ft_printf(message);
	exit(1);
}

void	ft_exec_cmd(char *cmd, char *envp[])
{
	char	**array_arg_cmd;
	char	*p_args;

	array_arg_cmd = ft_split(cmd, ' '); //colocar em outra função p pegar o path
	p_args = ft_strjoin("/bin/", array_arg_cmd[0]);
	execve(p_args, array_arg_cmd, envp);
	// free(array_arg_cmd);
	ft_check_error("Process 1");
}

void	ft_set_stdin(char *file, int *fd)
{
	int		infile;

	infile = open(file, O_RDONLY);
	if (errno != 0)
	{
		ft_close_fd(fd);
		ft_check_error("Error File stdin");
	}
	dup2(infile, STDIN_FILENO);
	close(infile);
}

void	ft_exec_p1(char *argv[], int *fd, char *envp[], int argc)
{
	ft_set_stdin(argv[1], fd);
	dup2(fd[1], STDOUT_FILENO);
	ft_set_stdout(argv[argc - 1]);
	ft_close_fd(fd);
	ft_exec_cmd(argv[2], envp);
}

void	ft_exec_p2(char *argv[], int *fd, char *envp[], int argc)
{
	dup2(fd[0], STDIN_FILENO);
	ft_set_stdout(argv[argc - 1]);
	ft_close_fd(fd);
	ft_exec_cmd(argv[3], envp);
}

void	ft_error_fork(char *argv[], int *fd, int argc, char *message)
{
	ft_close_fd(fd);
	ft_error(argv[argc - 1], message);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	int		pid1;
	int		pid2;
	int		wstatus2;

	if (argc < 4)
		ft_error(argv[argc - 1], "Error: Wrong number of args");
	if (pipe(fd) == -1)
		ft_error(argv[argc - 1], "Error: Pipe error");
	pid1 = fork();
	if (pid1 == -1)
		ft_error_fork(argv, fd, argc, "Fork 1 error");
	if (pid1 == 0)
		ft_exec_p1(argv, fd, envp, argc);
	pid2 = fork();
	if (pid2 == -1)
		ft_error_fork(argv, fd, argc, "Fork 2 error");
	if (pid2 == 0)
		ft_exec_p2(argv, fd, envp, argc);
	ft_close_fd(fd);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, &wstatus2, 0);
	if (wstatus2 != 0)
		ft_check_error("Process 2");
	return (0);
}
