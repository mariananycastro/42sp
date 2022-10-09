/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 17:00:04 by mariana           #+#    #+#             */
/*   Updated: 2022/10/09 20:43:02 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	int		pid;

	errno = 0;
	if (argc <= 4)
		ft_error("Usage: ./pipex [file] [cmd1] [cmd2] [file2]\n");
	else
	{
		if (pipe(fd) == -1)
			ft_error("Error: Pipe\n");
		pid = fork();
		if (pid == -1)
			ft_error_fork(fd, "Error: Fork\n");
		if (pid == 0)
			ft_exec_p1(argv, fd, envp);
		waitpid(pid, NULL, 0);
		pid = fork();
		if (pid == -1)
			ft_error_fork(fd, "Error: Fork\n");
		if (pid == 0)
			ft_exec_p2(argv, fd, envp, argc);
		ft_close_fd(fd);
		waitpid(pid, NULL, 0);
		return (0);
	}
}
