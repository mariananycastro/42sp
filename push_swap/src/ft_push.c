/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:05:48 by mariana           #+#    #+#             */
/*   Updated: 2023/02/11 20:06:30 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_index_list	*ft_push(t_index_list **list_from, t_index_list *list_to)
{
	t_index_list	*new_node;
	t_index_list	*next_node;
	int				i;
	int				end;

	new_node = ft_removed_node(list_from);
	end = list_to->previous->index + 1;
	list_to->previous->next = new_node;
	new_node->previous = list_to->previous;
	new_node->next = list_to;
	list_to->previous = new_node;
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
