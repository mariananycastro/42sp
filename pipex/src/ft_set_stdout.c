/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_stdout.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 20:23:15 by mariana           #+#    #+#             */
/*   Updated: 2022/10/02 20:24:39 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_set_stdout(char *file2)
{
	int		outfile;

	outfile = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_check_error("Error File stdout");
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
}
