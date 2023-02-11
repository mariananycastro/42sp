/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:02:34 by mariana           #+#    #+#             */
/*   Updated: 2023/02/11 20:09:57 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_index_list	*ft_create_lst(void *content)
{
	t_index_list	*first_item;

	if (!content)
		return (NULL);
	first_item = ft_create_node();
	if (!first_item)
		return (NULL);
	first_item->content = content;
	first_item->index = 0;
	first_item->previous = first_item;
	first_item->next = first_item;
	return (first_item);
}
