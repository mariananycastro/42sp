/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:30:17 by mariana           #+#    #+#             */
/*   Updated: 2023/02/24 14:08:00 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_index_stack	*ft_create_stack(int new_value)
{
	t_index_stack	*first_item;

	if (!new_value)
		return (NULL);
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
