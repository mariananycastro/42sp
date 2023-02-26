/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_order.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:24:03 by mariana           #+#    #+#             */
/*   Updated: 2023/02/26 17:44:50 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_set_order(t_index_stack **stack_a)
{
	t_index_stack	*tmp1;
	t_index_stack	*tmp2;
	int				i;
	int				j;
	t_index_stack	*biggest;

	tmp1 = (*stack_a);
	tmp2 = (*stack_a);
	biggest = tmp1;
	i = 0;
	while (i++ <= (*stack_a)->previous->index)
	{
		if (biggest->value < tmp1->next->value)
			biggest = tmp1->next;
		j = 0;
		while (j++ <= (*stack_a)->previous->index)
		{
			if (tmp1->value > tmp2->value)
				tmp1->position++;
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (biggest->position);
}
