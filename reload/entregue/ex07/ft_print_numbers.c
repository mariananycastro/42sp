/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastro <mariananycastro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 00:15:02 by mcastro           #+#    #+#             */
/*   Updated: 2022/03/28 00:16:14 by mcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_print_numbers(void)
{
	int	zero;
	int	nine;
	int	number;

	zero = 48;
	nine = 57;
	number = zero;
	while (number <= nine)
	{
		ft_putchar(number);
		number++;
	}
}
