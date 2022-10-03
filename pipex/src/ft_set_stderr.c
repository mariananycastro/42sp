/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_stderr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 21:32:34 by mariana           #+#    #+#             */
/*   Updated: 2022/10/02 21:35:56 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_set_stderr(char *file2)
{
	int		outfile;

	outfile = open(file2, O_WRONLY | O_CREAT, 0644);
	dup2(outfile, STDERR_FILENO);
	close(outfile);
}
