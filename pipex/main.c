/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 17:00:04 by mariana           #+#    #+#             */
/*   Updated: 2022/09/24 17:11:18 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <sys/types.h>
// #include <sys/stat.h>
// #include <string.h>
#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int		infile;
	int		outfile;
	int		i;
	int		last_arg_index;
	char	**array;
	int		process;

	if (argc < 4)
		return (ERRARG);
	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		return (ERRMISSINFILE);
	dup2(infile, STDIN_FILENO);
	close(infile);
	outfile = open(argv[argc - 1], O_WRONLY);
	if (outfile == -1)
		return (ERRMISSOUTFILE);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	i = 2;
	last_arg_index = argc - 2;
	// separa aqui
	array = ft_split(argv[i], ' ');
	if (!array)
		return (ERRARGS);
	process = execlp(array[0], *array, NULL);
	if (process < 0)
		return (ERRPROCESS);
	return (0);
}
