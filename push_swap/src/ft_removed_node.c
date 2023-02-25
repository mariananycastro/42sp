/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_removed_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:04:54 by mariana           #+#    #+#             */
/*   Updated: 2023/02/25 12:20:45 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_index_stack	*ft_removed_node(t_index_stack **node)
{
	t_index_stack	*node_copy;
	t_index_stack	*i_node;
	int				new_index;
	int				max_index;

	if (!*node)
		return (NULL);
	node_copy = *node;
	if (!node_copy)
		return (NULL);
	node_copy->previous->next = node_copy->next;
	node_copy->next->previous = node_copy->previous;
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
	return (node_copy);
}
