/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:29:45 by mariana           #+#    #+#             */
/*   Updated: 2023/02/15 19:29:48 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_to_stack(t_index_stack *first_of_stack, void *new_content)
{
	t_index_stack	*new_node;

	if (!first_of_stack || !new_content)
		return ;
	new_node = ft_create_node();
	if (!new_node)
		return ;
	new_node->content = new_content;
	new_node->index = first_of_stack->previous->index + 1;
	new_node->next = first_of_stack;
	new_node->previous = first_of_stack->previous;
	first_of_stack->previous->next = new_node;
	first_of_stack->previous = new_node;
}
