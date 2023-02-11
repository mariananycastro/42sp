/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:04:35 by mariana           #+#    #+#             */
/*   Updated: 2023/02/11 20:06:15 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_delete_list(t_index_list **node)
{
	t_index_list	*current;
	t_index_list	*next;
	int				i;
	int				end;

	current = *node;
	if (!node)
		return ;
	i = 0;
	end = current->previous->index;
	while (current && i <= end)
	{
		next = current->next;
		free(current);
		current = next;
		i++;
	}
}
