/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:44:28 by mariana           #+#    #+#             */
/*   Updated: 2023/03/04 21:58:46 by mariana          ###   ########.fr       */
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
		next_node = next_node->next;
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

void	ft_sort_4(t_index_stack **stack)
{
	t_index_stack	*stack_b;

	stack_b = NULL;
	if ((*stack)->next->position == 3)
		ft_swap_a(stack);
	else if ((*stack)->previous->position == 3)
		ft_reverse_rotate_a(stack);
	else if ((*stack)->next->next->position == 3)
	{
		ft_reverse_rotate_a(stack);
		if (!ft_is_sorted(stack))
			ft_reverse_rotate_a(stack);
	}
	if (!ft_is_sorted(stack))
	{
		ft_push_b(&stack_b, stack);
		ft_sort_3(stack);
		ft_push_all(&stack_b, stack);
		ft_rotate_a(stack);
	}
}

void	ft_move_first_two(t_index_stack **stack_a, t_index_stack **stack_b)
{
	int				i;

	i = (*stack_a)->previous->index;
	while (i > 2)
	{
		if ((*stack_a)->position != 0 && (*stack_a)->position != 1 && \
			(*stack_a)->next->position != 0 && (*stack_a)->next->position != 1
			&& (*stack_a)->previous->position != 0
			&& (*stack_a)->previous->position != 1
		)
			ft_reverse_rotate_a(stack_a);
		else
		{
			if ((*stack_a)->next->position == 0
				|| (*stack_a)->next->position == 1)
				ft_rotate_a(stack_a);
			else if ((*stack_a)->previous->position == 0
				|| (*stack_a)->previous->position == 1)
				ft_reverse_rotate_a(stack_a);
			ft_push_b(stack_b, stack_a);
			i--;
		}
	}
}

void	ft_sort_5(t_index_stack **stack)
{
	t_index_stack	*stack_b;

	stack_b = NULL;
	ft_move_first_two(stack, &stack_b);
	if (!ft_is_sorted(stack))
		ft_sort_3(stack);
	if (ft_is_sorted(&stack_b))
		ft_swap_b(&stack_b);
	ft_push_all(&stack_b, stack);
}
