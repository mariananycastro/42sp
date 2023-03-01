/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:47:06 by mariana           #+#    #+#             */
/*   Updated: 2023/02/28 20:47:37 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_all(t_index_stack **stack_b, t_index_stack **stack_a)
{
	while (*stack_b)
		ft_push_a(stack_b, stack_a);
}
