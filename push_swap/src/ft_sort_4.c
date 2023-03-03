/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:56:04 by mariana           #+#    #+#             */
/*   Updated: 2023/03/03 19:56:26 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_4(t_index_stack **stack)
{
	t_index_stack	*stack_b;

	stack_b = NULL;
	if ((*stack)->next->position == 3)
		ft_rotate_a(stack);
	else if ((*stack)->previous->position == 3)
		ft_reverse_rotate_a(stack);
	else if ((*stack)->next->next->position == 3)
	{
		ft_reverse_rotate_a(stack);
		ft_reverse_rotate_a(stack);
	}
	ft_push_b(&stack_b, stack);
	ft_sort_3(stack);
	ft_push_all(&stack_b, stack);
	ft_rotate_a(stack);
}
