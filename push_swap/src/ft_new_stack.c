/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:30:58 by mariana           #+#    #+#             */
/*   Updated: 2023/02/26 19:22:42 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_index_stack	*ft_new_stack(t_index_stack **node)
{
	t_index_stack	*new_stack;

	new_stack = ft_removed_node(node);
	new_stack->next = new_stack;
	new_stack->previous = new_stack;
	new_stack->index = 0;
	return (new_stack);
}
