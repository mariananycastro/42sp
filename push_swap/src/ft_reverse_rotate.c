/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:03:49 by mariana           #+#    #+#             */
/*   Updated: 2023/02/15 19:27:42 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_index_stack	*ft_reverse_rotate(t_index_stack *first_node)
{
	int				i;
	t_index_stack	*next_node;

	if (!first_node)
		return (NULL);
	i = first_node->index;
	first_node->index = first_node->previous->index;
	next_node = first_node->next;
	while (next_node && i <= next_node->index)
	{
		next_node->index = i;
		next_node = next_node->next;
		i++;
	}
	ft_printf("rr");
	return (first_node->next);
}
