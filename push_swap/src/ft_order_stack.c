/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:43:54 by mariana           #+#    #+#             */
/*   Updated: 2023/02/28 20:28:18 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_index_stack **stack)
{	
	if ((*stack)->position == 0)
	{
		ft_swap_a(*stack);
		ft_rotate_a(stack);
	}
	else if ((*stack)->position == 1)
	{
		if ((*stack)->next->position == 0)
			ft_swap_a(*stack);
		else
			ft_reverse_rotate_a(stack);
	}
	else
	{
		if ((*stack)->next->position == 0)
			ft_rotate_a(stack);
		else
		{
			ft_swap_a(*stack);
			ft_reverse_rotate_a(stack);
		}
	}
}

void	ft_order_stack(t_index_stack **stack_a, int stack_size)
{
	int	max_bits;

	if (ft_is_sorted(stack_a))
		return ;
	max_bits = ft_max_bits(stack_a);
	if (stack_size == 2)
		ft_swap_a(*stack_a);
	else if (stack_size == 3)
		ft_sort_3(stack_a);
	else
		ft_radix_order(stack_a, max_bits);
}
