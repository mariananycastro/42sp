/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:54:05 by mariana           #+#    #+#             */
/*   Updated: 2022/06/12 13:34:21 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int ft_decimal(int number)
{
    int         size;
    int         decimal_place;
    long int    copy_n;

	copy_n = number;

    size = 0;
    if (copy_n < 0)
    {
        copy_n = copy_n * -1;
        size++;
    }
    decimal_place = 1;
    while (copy_n / 10 >= 1)
    {
        decimal_place++;
        copy_n = copy_n / 10;
    }
    size = size + decimal_place;
    ft_putnbr_fd(number, 1);
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

static int ft_size(unsigned int number)
{
    int            size;
    int            decimal_place;
    unsigned int   copy_n;

	copy_n = number;

    size = 0;
    decimal_place = 1;
    while (copy_n / 10 != 0)
    {
        decimal_place++;
        copy_n = copy_n / 10;
    }
    size = size + decimal_place;
    return (size);
}

static int ft_unsigned_decimal(unsigned int number)
{
    int            size;
    int            i;
    unsigned int   copy_n;
    char * temp;

	copy_n = number;
    size = ft_size(number);
    i = size;
    temp = ft_calloc(size + 1, sizeof(char));
    while (copy_n != 0)
    {
        temp[i - 1] = (copy_n % 10) + 48;
        copy_n = copy_n / 10;
        i--;
    }
    ft_string(temp);
    free(temp);
    return (size);
}

static int	ft_change_base(unsigned long nbr, unsigned int base_number, char *char_base)
{
    int size;

    size = 1;
	if (nbr >= base_number)
		size = size + ft_change_base(nbr / base_number, base_number, char_base);
	ft_putchar_fd(char_base[nbr % base_number], 1);
    return(size);
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

void	ft_put_ptr(unsigned long long num)
{
    // printf("final = '%lld'\n", num);
    // printf("--- comeco put---\n");
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
        // printf("final = '%lld'\n", num);
		if (num <= 9)
        {
            // printf("if num = '%lld'\n", num + '0');
			ft_putchar_fd((num + '0'), 1);
        }
		else
        {
            // printf(" else num = '%lld'\n", num - 10 + 'a');
			ft_putchar_fd((num - 10 + 'a'), 1);
        }
	}
    // printf("--- final put---\n");
}

// static int	ft_change_to_pointer(unsigned long nbr, unsigned int base_number, char *char_base)
// {
//     int size;

//     size = 1;
// 	if (nbr >= base_number)
// 		size = size + ft_change_to_pointer(nbr / base_number, base_number, char_base);
//     else
//     {
//         if (nbr <= 9)
//             ft_putchar_fd((nbr + '0'), 1);
//         else
//             ft_putchar_fd((nbr - 10 + 'a'), 1);
//     }
//     return(size);
// }


static int ft_pointer(unsigned long position)
{
    int size;
    // char *p_position;

    size = 2;
    ft_putstr_fd("0x", 2);
    // if (position == 0)
    //     write(1, "0", 1);
    // else
    ft_put_ptr(position);
    // printf("\n");
    // ft_change_to_pointer(position, 16, "0123456789abcdef");
    // size = size + ft_change_to_base(position, 16, "0123456789abcdef");
    return (size);
}

int get_va_arg(int size, char c, va_list list)
{
    int item_size;

    item_size = 0;
    if (c == 'd' || c == 'i')
        item_size = ft_decimal(va_arg(list, int));
    if (c == 'u')
        item_size = ft_unsigned_decimal(va_arg(list, unsigned int));
    if (c == 'x')
        item_size = ft_hexadecimal(va_arg(list, unsigned int), "0123456789abcdef");
    if (c == 'X')
        item_size = ft_hexadecimal(va_arg(list, unsigned int), "0123456789ABCDEF");
    if (c == 'c')
        item_size = ft_single_char(va_arg(list, int));
    if (c == 's')
        item_size = ft_string(va_arg(list, char *));
    if (c == 'p')
        item_size = ft_pointer(va_arg(list, unsigned long));
    if (c == '%')
    {
        ft_putchar_fd('%', 1);
        size++;
    }
    // else error
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
            i++;
        }
        else
        {
            ft_putchar_fd(phrase[i], 1);
            size++;
        }
        i++;
    }
    return (size);
}


// int	ft_print_ptr(unsigned long long ptr)
// {
// 	int	print_length;

// 	print_length = 0;
// 	print_length += write(1, "0x", 2);
//     printf("'%d'", print_length);
// 	// if (ptr == 0)
// 	// 	print_length += write(1, "0", 1);
// 	// if 
// 	// {
// 		ft_put_ptr(ptr);
// 	// }
// 	return (print_length);
// }