/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:14:15 by mariana           #+#    #+#             */
/*   Updated: 2023/03/03 20:14:36 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_5(t_index_stack **stack)
{
	t_index_stack	*stack_b;
	int				i;

	stack_b = NULL;
	i = (*stack)->previous->index;
	while (i > 2)
	{
		if ((*stack)->position == 0 || (*stack)->position == 1)
		{
			ft_push_b(&stack_b, stack);
			i--;
		}
		ft_rotate_a(stack);
	}
	ft_sort_3(stack);
	if (ft_is_sorted(&stack_b))
		ft_swap_b(&stack_b);
	ft_push_all(&stack_b, stack);
}
