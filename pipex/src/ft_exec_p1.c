/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_p1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 21:28:52 by mariana           #+#    #+#             */
/*   Updated: 2022/10/09 21:45:42 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exec_p1(char *argv[], int *fd, char *envp[])
{
	char	*file_in;

	file_in = ft_get_file(argv[1], envp);
	ft_set_stdin(file_in, fd);
	dup2(fd[1], STDOUT_FILENO);
	ft_close_fd(fd);
	ft_exec_cmd(argv[2], envp);
}
