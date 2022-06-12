/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:23:48 by mariana           #+#    #+#             */
/*   Updated: 2022/06/12 17:33:51 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_to_base(unsigned long nbr, unsigned int base_number, char *char_base)
{
	int	size;

	size = 1;
	if (nbr >= base_number)
		size = size + ft_to_base(nbr / base_number, base_number, char_base);
	ft_putchar_fd(char_base[nbr % base_number], 1);
	return (size);
}
