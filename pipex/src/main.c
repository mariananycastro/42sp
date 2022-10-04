/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 17:00:04 by mariana           #+#    #+#             */
/*   Updated: 2022/10/04 14:21:35 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	int		pid1;
	int		pid2;

	errno = 0;
	if (argc < 4)
		ft_error(argv[argc - 1], "Error: Wrong number of args");
	if (pipe(fd) == -1)
		ft_error(argv[argc - 1], "Error: Pipe error");
	pid1 = fork();
	if (pid1 == -1)
		ft_error_fork(argv, fd, argc, "Fork 1 error");
	if (pid1 == 0)
		ft_exec_p1(argv, fd, envp);
	pid2 = fork();
	if (pid2 == -1)
		ft_error_fork(argv, fd, argc, "Fork 2 error");
	if (pid2 == 0)
		ft_exec_p2(argv, fd, envp, argc);
	return (0);
}
