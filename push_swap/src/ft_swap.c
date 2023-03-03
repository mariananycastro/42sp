/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:04:13 by mariana           #+#    #+#             */
/*   Updated: 2023/03/02 23:14:01 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_index_stack **first_node)
{
	int	copy_value;
	int	copy_index;
	int	copy_position;

	copy_value = (*first_node)->value;
	copy_index = (*first_node)->index;
	copy_position = (*first_node)->position;
	(*first_node)->value = (*first_node)->next->value;
	(*first_node)->index = (*first_node)->next->index;
	(*first_node)->position = (*first_node)->next->position;
	(*first_node)->next->value = copy_value;
	(*first_node)->next->index = copy_index;
	(*first_node)->next->position = copy_position;
}
