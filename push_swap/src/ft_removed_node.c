/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_removed_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:04:54 by mariana           #+#    #+#             */
/*   Updated: 2023/02/11 20:08:27 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_index_list	*ft_removed_node(t_index_list **node)
{
	t_index_list	*node_copy;
	t_index_list	*next_node;
	int				i;

	if (!*node)
		return (NULL);
	node_copy = *node;
	if (!node_copy)
		return (NULL);
	node_copy->previous->next = node_copy->next;
	node_copy->next->previous = node_copy->previous;
	*node = node_copy->next;
	next_node = node_copy->next;
	i = 0;
	while (node_copy && i < next_node->index)
	{
		next_node->index = i;
		next_node = next_node->next;
		i++;
	}
	return (node_copy);
}
