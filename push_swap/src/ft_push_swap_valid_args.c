/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_valid_args.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:41:07 by mariana           #+#    #+#             */
/*   Updated: 2023/02/23 11:43:15 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isnum(int number, char *arg)
{
    char    *alpha_formate;
    int     is_equal;

    alpha_formate = ft_itoa(number); 
    is_equal = ft_strncmp(alpha_formate, arg, ft_strlen(arg));
    free(alpha_formate);
    if (is_equal)
    {
        return (0);
    }
	return (1);
}

int ft_repeated_input(int current_number, char **argv, int i)
{
    int next_number;

    i++;
    while (argv[i])
    {
        next_number = ft_atoi(argv[i]);
        if (next_number == current_number)
            return (1);
        i++;   
    }
    return (0);
}

int ft_push_swap_valid_args(int argc, char **argv)
{
    int i;
    int current_number;

    if (argc <= 2)
    {
        write(2, "Error\n", 6);
        exit (1);
    }
    i = 1;
    while(argv[i])
    {
        current_number = ft_atoi(argv[i]);
        if(!ft_isnum(current_number, argv[i]) ||
            ft_repeated_input(current_number, argv, i) ||
            current_number < -2147483648 || current_number > 2147483647)
        {
            write(2, "Error\n", 6);
            exit (1);
        }
		i++;   
    }
    return (1);
}