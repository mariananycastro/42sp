/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:53:09 by mariana           #+#    #+#             */
/*   Updated: 2023/02/28 20:53:15 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_set_position(t_index_stack **stack_a)
{
	int	biggest_number;
	int	max_bits;

	biggest_number = ft_set_order(stack_a);
	max_bits = 0;
	while (biggest_number >> max_bits)
		max_bits++;
	return (max_bits);
}
