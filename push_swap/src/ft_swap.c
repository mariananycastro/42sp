/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:04:13 by mariana           #+#    #+#             */
/*   Updated: 2023/02/15 19:27:42 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_index_stack *first_node)
{
	int	content_copy;

	content_copy = first_node->value;
	first_node->value = first_node->next->value;
	first_node->next->value = content_copy;
}
