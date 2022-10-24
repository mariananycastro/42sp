/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 21:31:12 by mariana           #+#    #+#             */
/*   Updated: 2022/10/24 16:28:51 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exec_cmd(char *cmd, char *envp[])
{
	char	**array_arg_cmd;
	char	*path;

	array_arg_cmd = ft_split(cmd, ' ');
	path = ft_get_path(array_arg_cmd[0], envp);
	execve(path, array_arg_cmd, envp);
}
