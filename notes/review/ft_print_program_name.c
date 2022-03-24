/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastro <mariananycastro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:30:59 by mcastro           #+#    #+#             */
/*   Updated: 2022/02/16 18:09:49 by mcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[ ])
{
	int	pointer;

	if (argc > 0)
	{
		pointer = 0;
		while (argv[0][pointer])
		{
			write(1, &argv[0][pointer], 1);
			pointer++;
		}
		write(1, "\n", 1);
	}
	return (0);
}
