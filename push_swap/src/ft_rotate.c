/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:03:29 by mariana           #+#    #+#             */
/*   Updated: 2023/02/11 20:07:59 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_index_list	*ft_rotate(t_index_list *first_node)
{
	int				i;
	int				end;
	t_index_list	*next_node;

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
	ft_printf("r");
	return (first_node->previous);
}
