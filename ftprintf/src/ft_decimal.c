/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:21:47 by mariana           #+#    #+#             */
/*   Updated: 2022/06/12 17:35:00 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_decimal(int number)
{
	int			size;
	long int	copy_n;

	copy_n = number;
	size = 0;
	if (copy_n < 0)
	{
		write(1, "-", 1);
		size += ft_to_base(copy_n * -1, 10, "0123456789") + 1;
	}
	else
		size += ft_to_base(copy_n, 10, "0123456789");
	return (size);
}
