/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:51:48 by mariana           #+#    #+#             */
/*   Updated: 2023/03/03 20:52:04 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_b(t_index_stack **stack_b, t_index_stack **stack_a)
{
	if (!(*stack_b))
		*stack_b = ft_new_stack(stack_a);
	else
		ft_push(stack_a, stack_b);
	write(1, "pb\n", 3);
}

void	ft_swap_b(t_index_stack **stack_b)
{
	ft_swap(stack_b);
	write(1, "sb\n", 3);
}
