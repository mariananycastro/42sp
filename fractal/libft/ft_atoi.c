/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 22:00:42 by mariana           #+#    #+#             */
/*   Updated: 2022/07/30 20:26:27 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_turn_to_number(int number, char str)
{
	int	new_number;

	new_number = str - 48;
	return ((number * 10) + new_number);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	number;
	int	is_neg;

	i = 0;
	number = 0;
	is_neg = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			is_neg = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		number = ft_turn_to_number(number, str[i]);
		i++;
	}
	return (number * is_neg);
}
