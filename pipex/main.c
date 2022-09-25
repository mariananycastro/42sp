/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 17:00:04 by mariana           #+#    #+#             */
/*   Updated: 2022/09/25 11:53:53 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_set_stdin(char *file)
{
	int		infile;

	infile = open(file, O_RDONLY);
	// ou criar arquivo p nao dar erro 
	if (infile == -1)
		return (1);
	dup2(infile, STDIN_FILENO);
	close(infile);
	return (0);
}

int	ft_set_stdout(char *file2)
{
	int		outfile;

	outfile = open(file2, O_WRONLY);
	// apagar tudo o q estiver no arquivo ou criar arquivo
	if (outfile == -1)
		return (1);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	return (0);
}

int	ft_exec_cmd(char *cmd, char *envp[])
{
	char	**array_arg_cmd;
	int		process;
	char	*p_args;

	array_arg_cmd = ft_split(cmd, ' ');
	p_args = ft_strjoin("/bin/", array_arg_cmd[0]);
	process = execve(p_args, array_arg_cmd, envp);
	if (process < 0)
		return (1);
	return (0);
}

void	ft_close_fd(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}

int	ft_exec_p1(char *argv[], int *fd, char *envp[])
{
	if (ft_set_stdin(argv[1]) != 0)
		return (ERRINFILE);
	dup2(fd[1], STDOUT_FILENO);
	ft_close_fd(fd);
	ft_exec_cmd(argv[2], envp);
	return (0);
}

int	ft_exec_p2(char *argv[], int *fd, char *envp[], int argc)
{
	dup2(fd[0], STDIN_FILENO);
	if (ft_set_stdout(argv[argc - 1]) != 0)
		return (ERROUTFILE);
	ft_close_fd(fd);
	ft_exec_cmd(argv[3], envp);
	return (0);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	int		pid2;
	int		pid1;

	if (argc < 4)
		return (ERRARG);
	if (pipe(fd) == -1)
		return (ERRPIPE);
	pid1 = fork();
	if (pid1 == -1)
		return (ERRFORK);
	if (pid1 == 0)
		ft_exec_p1(argv, fd, envp);
	pid2 = fork();
	if (pid2 == -1)
		return (ERRFORK);
	if (pid2 == 0)
		ft_exec_p2(argv, fd, envp, argc);
	ft_close_fd(fd);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
