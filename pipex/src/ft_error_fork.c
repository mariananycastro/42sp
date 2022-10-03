/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_fork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 21:25:08 by mariana           #+#    #+#             */
/*   Updated: 2022/10/02 21:36:01 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error_fork(char *argv[], int *fd, int argc, char *message)
{
	ft_close_fd(fd);
	ft_error(argv[argc - 1], message);
}
