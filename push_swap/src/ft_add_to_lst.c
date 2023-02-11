/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:03:05 by mariana           #+#    #+#             */
/*   Updated: 2023/02/11 20:07:37 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_to_lst(t_index_list *first_of_lst, void *new_content)
{
	t_index_list	*new_node;

	if (!first_of_lst || !new_content)
		return ;
	new_node = ft_create_node();
	if (!new_node)
		return ;
	new_node->content = new_content;
	new_node->index = first_of_lst->previous->index + 1;
	new_node->next = first_of_lst;
	new_node->previous = first_of_lst->previous;
	first_of_lst->previous->next = new_node;
	first_of_lst->previous = new_node;
}
