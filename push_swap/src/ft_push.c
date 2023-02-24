/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:05:48 by mariana           #+#    #+#             */
/*   Updated: 2023/02/15 19:31:30 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_index_stack	*ft_push(t_index_stack **stack_from, t_index_stack *stack_to)
{
	t_index_stack	*new_node;
	t_index_stack	*next_node;
	int				i;
	int				end;

	new_node = ft_removed_node(stack_from);
	end = stack_to->previous->index + 1;
	stack_to->previous->next = new_node;
	new_node->previous = stack_to->previous;
	new_node->next = stack_to;
	stack_to->previous = new_node;
	next_node = new_node;
	i = 0;
	while (new_node && i <= end)
	{
		next_node->index = i;
		next_node = next_node->next;
		i++;
	}
	return (new_node);
}