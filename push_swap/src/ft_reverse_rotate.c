/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:04:07 by mariana           #+#    #+#             */
/*   Updated: 2023/02/26 20:04:47 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_index_stack	*ft_reverse_rotate(t_index_stack *first_node)
{
	int				i;
	int				end;
	t_index_stack	*next_node;

	if (!first_node)
		return (NULL);
	i = 0;
	end = first_node->previous->index;
	next_node = first_node->previous;
	while (next_node && i <= end)
	{
		next_node->index = i;
		next_node = next_node->next;
		i++;
	}
	return (first_node->previous);
}
// deveria retornar?