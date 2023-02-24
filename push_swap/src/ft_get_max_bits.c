/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_max_bits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:19:51 by mariana           #+#    #+#             */
/*   Updated: 2023/02/24 15:22:23 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_max_bits(int n)
{
	int	max_bits;

	max_bits = 0;
	while (n)
	{
		max_bits++;
		n >>= 1;
	}
	return (max_bits);
}
