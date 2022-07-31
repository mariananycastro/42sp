/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:31:28 by mariana           #+#    #+#             */
/*   Updated: 2022/07/30 20:21:32 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_pointer(unsigned long pointer)
{
	int	size;

	if (pointer == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	size = 2;
	ft_putstr_fd("0x", 1);
	size += ft_to_base(pointer, 16, "0123456789abcdef");
	return (size);
}
