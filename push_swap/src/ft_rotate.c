/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:03:36 by mariana           #+#    #+#             */
/*   Updated: 2023/02/26 20:05:03 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_index_stack	*ft_rotate(t_index_stack *first_node)
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
	return (first_node->next);
}
