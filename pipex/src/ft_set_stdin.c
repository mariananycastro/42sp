/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_stdin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 21:30:12 by mariana           #+#    #+#             */
/*   Updated: 2022/10/02 21:30:24 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_set_stdin(char *file, int *fd)
{
	int		infile;

	infile = open(file, O_RDONLY);
	if (errno != 0)
	{
		ft_close_fd(fd);
		ft_check_error("Error File stdin");
	}
	dup2(infile, STDIN_FILENO);
	close(infile);
}
