/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:54:05 by mariana           #+#    #+#             */
/*   Updated: 2022/06/12 16:14:04 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"


# include <stdio.h>

static int	ft_change_base(unsigned long nbr, unsigned int base_number, char *char_base)
{
    int size;

    size = 1;
	if (nbr >= base_number)
		size = size + ft_change_base(nbr / base_number, base_number, char_base);
	ft_putchar_fd(char_base[nbr % base_number], 1);
    return(size);
}

static int ft_decimal(int number)
{

    int         size;
    long int    copy_n;

	copy_n = number;
    size = 0;
    if (copy_n < 0)
    {
        write(1, "-", 1);
        size += ft_change_base(copy_n * -1, 10, "0123456789") + 1;
    }
    else
        size += ft_change_base(copy_n, 10, "0123456789");
    return (size);
}

static int ft_string(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        ft_putchar_fd(str[i], 1);
        i++;
    }
    return (i);
}

static int ft_unsigned_decimal(unsigned int number)
{
    int size;

	size = 0;
	if (number >= 10)
		size += ft_unsigned_decimal((number / 10));
	ft_putchar_fd(((number % 10) + '0'), 1);
	return (size + 1);
}

static int ft_hexadecimal(unsigned int number, char* base)
{
    int size;

    size = 0;
    size = ft_change_base(number, 16, base);
    return (size);
}

static int ft_single_char(int caracter)
{
    ft_putchar_fd(caracter, 1);
    return(1);
}

static int ft_pointer(unsigned long position)
{
    int size;

    size = 2;
    ft_putstr_fd("0x", 2);
    size = size + ft_change_base(position, 16, "0123456789abcdef");
    return (size);
}

int get_va_arg(int size, char c, va_list list)
{
    int item_size;
    char *list_arg;

    item_size = 0;
    if (c == 'd' || c == 'i')
        item_size = ft_decimal(va_arg(list, long int));
    if (c == 'u')
        item_size = ft_unsigned_decimal(va_arg(list, unsigned int));
    if (c == 'x')
        item_size = ft_hexadecimal(va_arg(list, unsigned int), "0123456789abcdef");
    if (c == 'X')
        item_size = ft_hexadecimal(va_arg(list, unsigned int), "0123456789ABCDEF");
    if (c == 'c')
        item_size = ft_single_char(va_arg(list, int));
    if (c == 's')
    {
        list_arg = va_arg(list, char *);
        if (list_arg)
            item_size = ft_string(list_arg);
    }
    if (c == 'p')
        item_size = ft_pointer(va_arg(list, unsigned long));
    if (c == '%')
    {
        ft_putchar_fd('%', 1);
        size++;
    }
    return (size + item_size);
}

int ft_printf(const char *phrase, ...)
{
    int size;
    int i;
    va_list list;

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
