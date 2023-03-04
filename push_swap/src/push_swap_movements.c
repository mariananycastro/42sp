/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_movements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:08:03 by mariana           #+#    #+#             */
/*   Updated: 2023/03/03 21:08:05 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_all(t_index_stack **stack_b, t_index_stack **stack_a)
{
	while (*stack_b)
		ft_push_a(stack_b, stack_a);
}

void	ft_push(t_index_stack **stack_from, t_index_stack **stack_to)
{
	t_index_stack	*new_node;
	t_index_stack	*next_node;
	int				i;
	int				last_index;

	new_node = ft_removed_node(stack_from);
	last_index = (*stack_to)->previous->index + 1;
	new_node->previous = (*stack_to)->previous;
	new_node->next = (*stack_to);
	(*stack_to)->previous->next = new_node;
	(*stack_to)->previous = new_node;
	*stack_to = new_node;
	next_node = new_node;
	i = 0;
	while (new_node && i <= last_index)
	{
		next_node->index = i;
		next_node = next_node->next;
		i++;
	}
}

void	ft_reverse_rotate(t_index_stack **first_node)
{
	int				i;
	int				end;
	t_index_stack	*next_node;

	i = 0;
	end = (*first_node)->previous->index;
	*first_node = (*first_node)->previous;
	next_node = (*first_node);
	while (next_node && i <= end)
	{
		next_node->index = i;
		next_node = next_node->next;
		i++;
	}
}

void	ft_rotate(t_index_stack **first_node)
{
	int				i;
	int				end;
	t_index_stack	*next_node;

	i = 0;
	end = (*first_node)->previous->index;
	*first_node = (*first_node)->next;
	next_node = (*first_node);
	while (next_node && i <= end)
	{
		next_node->index = i;
		next_node = next_node->next;
		i++;
	}
}

void	ft_swap(t_index_stack **first_node)
{
	int	copy_value;
	int	copy_index;
	int	copy_position;

	copy_value = (*first_node)->value;
	copy_index = (*first_node)->index;
	copy_position = (*first_node)->position;
	(*first_node)->value = (*first_node)->next->value;
	(*first_node)->index = (*first_node)->next->index;
	(*first_node)->position = (*first_node)->next->position;
	(*first_node)->next->value = copy_value;
	(*first_node)->next->index = copy_index;
	(*first_node)->next->position = copy_position;
}
