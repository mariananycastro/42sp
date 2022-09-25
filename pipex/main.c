/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 17:00:04 by mariana           #+#    #+#             */
/*   Updated: 2022/09/24 23:29:31 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <sys/types.h>
// #include <sys/stat.h>
// #include <string.h>
#include "pipex.h"

int	ft_set_stdin(char *file1)
{
	int		infile;

	infile = open(file1, O_RDONLY);
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

int	main(int argc, char *argv[], char *envp[])
{
	int		i;
	char	**array_arg_cmd;
	char	*p_args;
	int		process;

	if (argc < 4)
		return (ERRARG);
	if (ft_set_stdin(argv[1]) != 0)
		return (ERRMISSINFILE);
	if (ft_set_stdout(argv[argc - 1]) != 0)
		return (ERRMISSOUTFILE);

	i = 2;
	array_arg_cmd = ft_split(argv[i], ' ');
	p_args = ft_strjoin("/bin/", array_arg_cmd[0]);
	process = execve(p_args, array_arg_cmd, envp);
	if (process < 0)
		return (ERRPROCESS);
	return (0);
}

// < file1 grep a1 | wc -w > file2 
// < file1 grep a1 > file2 
// < file1 ls -l > file2 