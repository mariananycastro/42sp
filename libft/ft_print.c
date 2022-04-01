/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 00:31:13 by mcastro           #+#    #+#             */
/*   Updated: 2022/03/31 22:10:57 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print(int argc, char *argv[ ])
{
	int	pointer;
	int	i;

	if (argc > 0)
	{
		pointer = 1;
		i = 0;
		while (argv[pointer])
		{
			while (argv[pointer][i])
			{
				write(1, &argv[pointer][i], 1);
				i++;
			}
			write (1, "\n", 1);
			i = 0;
			pointer++;
		}
	}
}
