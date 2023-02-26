/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_removed_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:04:54 by mariana           #+#    #+#             */
/*   Updated: 2023/02/26 11:14:44 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
