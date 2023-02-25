/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:43:54 by mariana           #+#    #+#             */
/*   Updated: 2023/02/25 15:51:12 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_order_stack(t_index_stack **stack_a, int stack_size)
{
	if (ft_is_sorted(stack_a))
		return ;
	else if (stack_size == 2)
		ft_swap_a(*stack_a);
	else if (stack_size == 3)
		ft_printf("3 numbers\n");
	else
		ft_radix_order(stack_a);
}
