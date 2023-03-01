/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:49:01 by mariana           #+#    #+#             */
/*   Updated: 2023/02/28 20:49:18 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a(t_index_stack **stack_from, t_index_stack **stack_to)
{
	ft_push(stack_from, stack_to);
	write(1, "pa\n", 3);
}
