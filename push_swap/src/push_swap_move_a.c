/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_move_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:47:21 by mariana           #+#    #+#             */
/*   Updated: 2023/03/03 20:52:01 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a(t_index_stack **stack_from, t_index_stack **stack_to)
{
	ft_push(stack_from, stack_to);
	write(1, "pa\n", 3);
}

void	ft_rotate_a(t_index_stack **stack_a)
{
	ft_rotate(stack_a);
	write(1, "ra\n", 3);
}

void	ft_reverse_rotate_a(t_index_stack **stack_a)
{
	ft_reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	ft_swap_a(t_index_stack **stack_a)
{
	ft_swap(stack_a);
	write(1, "sa\n", 3);
}
