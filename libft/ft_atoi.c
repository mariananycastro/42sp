/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 22:00:42 by mariana           #+#    #+#             */
/*   Updated: 2022/03/31 22:00:44 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_numeric(char caracter)
{
	if (caracter >= 48 && caracter <= 57)
		return (1);
	return (0);
}

int	ft_is_white_space(char caracter)
{
	if (caracter == 32 || (caracter >= 9 && caracter <= 13))
		return (1);
	return (0);
}

int	ft_turn_to_number(int number, char str)
{
	int	new_number;

	new_number = str - 48;
	return ((number * 10) + new_number);
}

int	ft_atoi(char *str)
{
	int	i;
	int	number;
	int	is_neg;

	i = 0;
	number = 0;
	is_neg = 1;
	while (ft_is_white_space(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			is_neg = is_neg * (-1);
		i++;
	}
	while (ft_is_numeric(str[i]))
	{
		number = ft_turn_to_number(number, str[i]);
		i++;
	}
	return (number * is_neg);
}
