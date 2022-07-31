/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:54:05 by mariana           #+#    #+#             */
/*   Updated: 2022/07/30 20:21:36 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	get_va_arg(int size, char c, va_list list)
{
	if (c == 'd' || c == 'i')
		size += ft_decimal(va_arg(list, int));
	if (c == 'u')
		size += ft_to_base(va_arg(list, unsigned int), 10, "0123456789");
	if (c == 'x')
		size += ft_to_base(va_arg(list, unsigned int), 16, "0123456789abcdef");
	if (c == 'X')
		size += ft_to_base(va_arg(list, unsigned int), 16, "0123456789ABCDEF");
	if (c == 'c')
	{
		ft_putchar_fd(va_arg(list, int), 1);
		size++;
	}
	if (c == 's')
		size += ft_string(va_arg(list, char *));
	if (c == 'p')
		size += ft_pointer(va_arg(list, unsigned long));
	if (c == '%')
	{
		ft_putchar_fd('%', 1);
		size++;
	}
	return (size);
}

int	ft_printf(const char *phrase, ...)
{
	int		size;
	int		i;
	va_list	list;

	i = 0;
	size = 0;
	va_start(list, phrase);
	while (phrase[i])
	{
		if (phrase[i] == '%' && phrase[i + 1])
		{
			size = get_va_arg(size, phrase[i + 1], list);
			i += 2;
		}
		else
		{
			ft_putchar_fd(phrase[i], 1);
			size++;
			i++;
		}
	}
	return (size);
}
