/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastro <mariananycastro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 00:30:43 by mcastro           #+#    #+#             */
/*   Updated: 2022/03/28 00:30:44 by mcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[ ])
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
			write(1, "\n", 1);
			i = 0;
			pointer++;
		}
	}
	return (0);
}
