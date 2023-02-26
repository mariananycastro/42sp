/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_order.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:44:33 by mariana           #+#    #+#             */
/*   Updated: 2023/02/26 16:40:47 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_index_stack	*ft_reverse_rotate_a(t_index_stack *stack_a)
{
	write(1, "ra\n", 3);
	return (ft_reverse_rotate(stack_a));
}

void	ft_push_b(t_index_stack **stack_from, t_index_stack **stack_to)
{
	ft_push(stack_from, stack_to);
	write(1, "pb\n", 3);
}

void	ft_push_a(t_index_stack **stack_from, t_index_stack **stack_to)
{
	ft_push(stack_from, stack_to);
	write(1, "pa\n", 3);
}

void	ft_radix_order(t_index_stack **stack_a)
{
	int				biggest_number;
	int				max_bits;
	t_index_stack	*stack_b;
	int				last_index;
	int				z;
	int				i;

	biggest_number = ft_set_order(stack_a);
	max_bits = ft_get_max_bits(biggest_number);
	stack_b = NULL;
	i = 0;
	z = 0;
	last_index = (*stack_a)->previous->index;
	while (i < max_bits)
	{
		while (z <= last_index)
		{
			if (!(((*stack_a)->position >> i) & 1) && !ft_stack_last_item(*stack_a))
			{
				if (!stack_b)
					stack_b = ft_new_stack(stack_a);
				else
					ft_push_b(stack_a, &stack_b);
			}
			else
				*stack_a = ft_reverse_rotate_a(*stack_a);
			z++;
		}
		while (stack_b)
		{
			ft_push_a(&stack_b, stack_a);
		}
		z = 0;
		i++;
	}
}
