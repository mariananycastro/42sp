/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:09:24 by mariana           #+#    #+#             */
/*   Updated: 2023/03/03 20:17:38 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_min(t_index_stack *stack)
{
	int				min;
	int				i;
	t_index_stack	*next_node;

	min = stack->position;
	next_node = stack;
	i = 0;
	while (i++ < 3)
	{
		if (min > next_node->position)
			min = next_node->position;
		next_node = stack->next;
	}
	return (min);
}

void	ft_sort_3(t_index_stack **stack)
{
	int	min;

	min = ft_find_min(*stack);
	if ((*stack)->position == min)
	{
		ft_swap_a(stack);
		ft_rotate_a(stack);
	}
	else if ((*stack)->position == min + 1)
	{
		if ((*stack)->next->position == min)
			ft_swap_a(stack);
		else
			ft_reverse_rotate_a(stack);
	}
	else
	{
		if ((*stack)->next->position == min)
			ft_rotate_a(stack);
		else
		{
			ft_swap_a(stack);
			ft_reverse_rotate_a(stack);
		}
	}
}
