/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_bits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:19:51 by mariana           #+#    #+#             */
/*   Updated: 2023/02/26 18:57:08 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max_bits(t_index_stack **stack_a)
{
	int	biggest_number;
	int	max_bits;

	biggest_number = ft_set_order(stack_a);
	max_bits = 0;
	while (biggest_number >> max_bits)
		max_bits++;
	return (max_bits);
}