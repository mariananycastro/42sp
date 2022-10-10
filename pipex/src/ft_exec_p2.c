/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_p2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 21:33:31 by mariana           #+#    #+#             */
/*   Updated: 2022/10/09 21:46:15 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exec_p2(char *argv[], int *fd, char *envp[], int argc)
{
	char	*file_out;

	file_out = ft_get_file(argv[argc - 1], envp);
	dup2(fd[0], STDIN_FILENO);
	ft_set_stdout(file_out);
	ft_close_fd(fd);
	ft_exec_cmd(argv[3], envp);
}
