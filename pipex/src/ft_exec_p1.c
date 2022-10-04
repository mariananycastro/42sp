/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_p1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 21:28:52 by mariana           #+#    #+#             */
/*   Updated: 2022/10/04 14:22:53 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exec_p1(char *argv[], int *fd, char *envp[])
{
	ft_set_stdin(argv[1], fd);
	dup2(fd[1], STDOUT_FILENO);
	ft_close_fd(fd);
	ft_exec_cmd(argv[2], envp);
}
