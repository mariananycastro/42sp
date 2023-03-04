/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:08:43 by mariana           #+#    #+#             */
/*   Updated: 2023/03/03 21:08:46 by mariana          ###   ########.fr       */
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

int	ft_set_position(t_index_stack **stack_a)
{
	int	biggest_number;
	int	max_bits;

	biggest_number = ft_set_order(stack_a);
	max_bits = 0;
	while (biggest_number >> max_bits)
		max_bits++;
	return (max_bits);
}

t_index_stack	*ft_create_node(void)
{
	t_index_stack	*node;

	node = malloc(sizeof(t_index_stack));
	if (!node)
		return (NULL);
	return (node);
}

int	ft_stack_last_item(t_index_stack *stack_a)
{
	return (stack_a->previous->value == stack_a->value);
}
