/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:53:47 by mariana           #+#    #+#             */
/*   Updated: 2023/03/03 21:05:57 by mariana          ###   ########.fr       */
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

t_index_stack	*ft_create_stack(int new_value)
{
	t_index_stack	*first_item;

	first_item = ft_create_node();
	if (!first_item)
		return (NULL);
	first_item->value = new_value;
	first_item->index = 0;
	first_item->position = 0;
	first_item->previous = first_item;
	first_item->next = first_item;
	return (first_item);
}

void	ft_delete_stack(t_index_stack **node)
{
	t_index_stack	*current;
	t_index_stack	*next;
	int				i;
	int				end;

	current = *node;
	if (!node)
		return ;
	i = 0;
	end = current->previous->index;
	while (current && i <= end)
	{
		next = current->next;
		free(current);
		current = next;
		i++;
	}
}

t_index_stack	*ft_removed_node(t_index_stack **node)
{
	t_index_stack	*node_copy;
	t_index_stack	*i_node;
	int				new_index;
	int				max_index;

	node_copy = *node;
	node_copy->previous->next = node_copy->next;
	node_copy->next->previous = node_copy->previous;
	if (ft_stack_last_item(*node))
		*node = NULL;
	else
	{
		*node = node_copy->next;
		max_index = (*node)->previous->index;
		new_index = 0;
		i_node = (*node);
		while (new_index < max_index)
		{
			i_node->index = new_index;
			i_node = i_node->next;
			new_index++;
		}
	}
	return (node_copy);
}

t_index_stack	*ft_new_stack(t_index_stack **node)
{
	t_index_stack	*new_stack;

	new_stack = ft_removed_node(node);
	new_stack->next = new_stack;
	new_stack->previous = new_stack;
	new_stack->index = 0;
	return (new_stack);
}
