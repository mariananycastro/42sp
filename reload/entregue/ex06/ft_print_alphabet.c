/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastro <mariananycastro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 00:11:44 by mcastro           #+#    #+#             */
/*   Updated: 2022/03/28 00:14:50 by mcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_print_alphabet(void)
{
	int	a;
	int	z;
	int	letter;

	a = 97;
	z = 122;
	letter = a;
	while (letter <= z)
	{
		ft_putchar(letter);
		letter++;
	}
}
