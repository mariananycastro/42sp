/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_p1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 21:28:52 by mariana           #+#    #+#             */
/*   Updated: 2022/10/02 22:01:35 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exec_p1(char *argv[], int *fd, char *envp[], int argc)
{
	ft_set_stdin(argv[1], fd);
	dup2(fd[1], STDOUT_FILENO);
	ft_close_fd(fd);
	ft_set_stderr(argv[argc - 1]);
	ft_exec_cmd(argv[2], envp);
}
