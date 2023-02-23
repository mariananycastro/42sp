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
	void	*content_copy;

	content_copy = first_node->content;
	first_node->content = first_node->next->content;
	first_node->next->content = content_copy;
	ft_printf("s");
}
