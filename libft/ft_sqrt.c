/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 00:24:00 by mcastro           #+#    #+#             */
/*   Updated: 2022/03/31 22:11:13 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt(int nb)
{
	int	sqrt;

	sqrt = 2;
	if (nb <= 0)
		return (0);
	else
	{
		while (sqrt <= nb / 2)
		{
			if (sqrt * sqrt == nb)
				return (sqrt);
			sqrt++;
		}
		return (0);
	}
}
