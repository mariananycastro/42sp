/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 17:00:04 by mariana           #+#    #+#             */
/*   Updated: 2022/10/02 22:17:21 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	int		pid1;
	int		pid2;
	int		wstatus1;
	int		wstatus2;

	errno = 0;
	if (argc < 4)
		ft_error(argv[argc - 1], "Error: Wrong number of args");
	if (pipe(fd) == -1)
		ft_error(argv[argc - 1], "Error: Pipe error");
	pid1 = fork();
	if (pid1 == -1)
		ft_error_fork(argv, fd, argc, "Fork 1 error");
	if (pid1 == 0)
		ft_exec_p1(argv, fd, envp, argc);
	waitpid(pid1, &wstatus1, 0);
	if (wstatus1 != 0)
		exit(0);

	pid2 = fork();
	if (pid2 == -1)
		ft_error_fork(argv, fd, argc, "Fork 2 error");
	if (pid2 == 0)
		ft_exec_p2(argv, fd, envp, argc);

	// ft_printf("%d", pid2);
	waitpid(pid2, &wstatus2, 0);
	if (wstatus2 != 0)
		exit(0);
	ft_close_fd(fd);
	return (0);
}
