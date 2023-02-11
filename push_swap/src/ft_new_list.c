/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:05:27 by mariana           #+#    #+#             */
/*   Updated: 2023/02/11 20:08:09 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_index_list	*ft_new_list(t_index_list **node)
{
	t_index_list	*new_list;

	new_list = ft_removed_node(node);
	new_list->next = new_list;
	new_list->previous = new_list;
	new_list->index = 0;
	return (new_list);
}
