/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_order.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:24:03 by mariana           #+#    #+#             */
/*   Updated: 2023/02/24 15:33:04 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_set_order(t_index_stack **stack_a)
{
	t_index_stack	*tmp1;
	t_index_stack	*tmp2;
	int				i;
	int				ii;
	int				biggest;

	tmp1 = (*stack_a);
	tmp2 = (*stack_a);
	biggest = tmp1->value;
	i = 0;
	ii = 0;
	while (i <= (*stack_a)->previous->index)
	{
		if (tmp1->value < tmp1->next->value)
			biggest = tmp1->next->value;
		while (ii <= (*stack_a)->previous->index)
		{
			if (tmp1->value > tmp2->value)
				tmp1->position++;
			tmp2 = tmp2->next;
			ii++;
		}
		ii = 0;
		tmp1 = tmp1->next;
		i++;
	}
	return (biggest);
}
