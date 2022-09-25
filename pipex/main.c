/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 17:00:04 by mariana           #+#    #+#             */
/*   Updated: 2022/09/25 10:21:01 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <sys/types.h>
// #include <sys/stat.h>
// #include <string.h>
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

int ft_exec_cmd(char *cmd, char *envp[])
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

int	main(int argc, char *argv[], char *envp[])
{
	int		i;
	char	**array_arg_cmd;
	char	*p_args;
	int		process;

	if (argc < 4)
		return (ERRARG);

	i = 2;
	int fd[2];
    if (pipe(fd) == -1)
		return (ERRPIPE);
	int pid1 = fork();
    if (pid1 < 0)
		return (ERRFORK);
	if (pid1 == 0) {
		if (ft_set_stdin(argv[1]) != 0)
			return (ERRINFILE);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
		ft_exec_cmd(argv[2], envp);
    }
	int pid2 = fork();
    if (pid2 < 0)
		return (ERRFORK);
    if (pid2 == 0) {
        dup2(fd[0], STDIN_FILENO);
		if (ft_set_stdout(argv[argc - 1]) != 0)
			return (ERROUTFILE);
        close(fd[0]);
        close(fd[1]);
        ft_exec_cmd(argv[3], envp);
    }
    close(fd[0]);
    close(fd[1]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
	return (0);
}
