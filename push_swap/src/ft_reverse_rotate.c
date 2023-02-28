/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:04:07 by mariana           #+#    #+#             */
/*   Updated: 2023/02/28 19:41:08 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_index_stack **first_node)
{
	int				i;
	int				end;
	t_index_stack	*next_node;

	i = 0;
	end = (*first_node)->previous->index;
	*first_node = (*first_node)->previous;
	next_node = (*first_node)->previous;
	while (next_node && i <= end)
	{
		next_node->index = i;
		next_node = next_node->next;
		i++;
	}
}
