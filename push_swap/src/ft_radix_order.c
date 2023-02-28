/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_order.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:44:33 by mariana           #+#    #+#             */
/*   Updated: 2023/02/28 20:17:43 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a(t_index_stack **stack_from, t_index_stack **stack_to)
{
	ft_push(stack_from, stack_to);
	write(1, "pa\n", 3);
}

void	ft_push_b(t_index_stack **stack_b, t_index_stack **stack_a)
{
	if (!(*stack_b))
		*stack_b = ft_new_stack(stack_a);
	else
		ft_push(stack_a, stack_b);
	write(1, "pb\n", 3);
}

void	ft_push_all(t_index_stack **stack_b, t_index_stack **stack_a)
{
	while (*stack_b)
		ft_push_a(stack_b, stack_a);
}

void	ft_radix_order(t_index_stack **stack_a, int max_bits)
{
	t_index_stack	*stack_b;
	int				last_index;
	int				z;
	int				i;

	stack_b = NULL;
	i = 0;
	max_bits = ft_max_bits(stack_a);
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
