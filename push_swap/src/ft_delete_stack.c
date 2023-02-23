/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:04:35 by mariana           #+#    #+#             */
/*   Updated: 2023/02/15 19:30:45 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_delete_stack(t_index_stack **node)
{
	t_index_stack	*current;
	t_index_stack	*next;
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
