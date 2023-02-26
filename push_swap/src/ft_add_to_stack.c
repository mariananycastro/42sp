/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:29:45 by mariana           #+#    #+#             */
/*   Updated: 2023/02/26 20:03:03 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_to_stack(t_index_stack *stack, int new_value)
{
	t_index_stack	*new_node;

	if (!stack)
		return ;
	new_node = ft_create_node();
	if (!new_node)
		return ;
	new_node->value = new_value;
	new_node->index = stack->previous->index + 1;
	new_node->position = 0;
	new_node->next = stack;
	new_node->previous = stack->previous;
	stack->previous->next = new_node;
	stack->previous = new_node;
}
