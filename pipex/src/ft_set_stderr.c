/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_stderr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 21:32:34 by mariana           #+#    #+#             */
/*   Updated: 2022/10/09 22:09:32 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_set_stderr(char *file2)
{
	int		outfile;

	outfile = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	dup2(outfile, STDERR_FILENO);
	close(outfile);
}
