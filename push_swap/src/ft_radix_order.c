/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_order.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:44:33 by mariana           #+#    #+#             */
/*   Updated: 2023/02/28 20:49:21 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_radix_order(t_index_stack **stack_a, int max_bits)
{
	t_index_stack	*stack_b;
	int				last_index;
	int				z;
	int				i;

	stack_b = NULL;
	i = 0;
	last_index = (*stack_a)->previous->index;
	while (i++ < max_bits)
	{
		z = 0;
		while (z++ <= last_index)
		{
			if (!ft_stack_last_item(*stack_a))
			{
				if (((*stack_a)->position >> (i - 1)) & 1)
					ft_rotate_a(stack_a);
				else
					ft_push_b(&stack_b, stack_a);
			}
		}
		ft_push_all(&stack_b, stack_a);
	}
}
