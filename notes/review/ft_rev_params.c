/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastro <mariananycastro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:34:53 by mcastro           #+#    #+#             */
/*   Updated: 2022/02/15 19:34:54 by mcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[ ])
{
	int	size;
	int	i;

	size = argc - 1;
	while (size > 0)
	{
		i = 0;
		while (argv[size][i])
		{
			write(1, &argv[size][i], 1);
			i++;
		}
		write(1, "\n", 1);
		size--;
	}
	return (0);
}
