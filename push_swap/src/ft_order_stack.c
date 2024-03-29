/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:43:54 by mariana           #+#    #+#             */
/*   Updated: 2023/03/03 20:14:21 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_order_stack(t_index_stack **stack_a, int stack_size)
{
	int	max_bits;

	if (ft_is_sorted(stack_a))
		return ;
	max_bits = ft_set_position(stack_a);
	if (stack_size == 2)
		ft_swap_a(stack_a);
	else if (stack_size == 3)
		ft_sort_3(stack_a);
	else if (stack_size == 4)
		ft_sort_4(stack_a);
	else if (stack_size == 5)
		ft_sort_5(stack_a);
	else
		ft_radix_order(stack_a, max_bits);
}
