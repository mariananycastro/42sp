/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 21:31:12 by mariana           #+#    #+#             */
/*   Updated: 2022/10/02 22:18:51 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exec_cmd(char *cmd, char *envp[])
{
	char	**array_arg_cmd;
	char	*p_args;

	array_arg_cmd = ft_split(cmd, ' '); //colocar em outra função p pegar o path
	p_args = ft_strjoin("/bin/", array_arg_cmd[0]);
	// se nao tiver comando raise error;
	ft_printf("%s", p_args);
	execve(p_args, array_arg_cmd, envp);
	ft_check_error("Process 1");
}
