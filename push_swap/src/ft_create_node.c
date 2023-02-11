/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 20:01:24 by mariana           #+#    #+#             */
/*   Updated: 2023/02/11 20:02:11 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_index_list	*ft_create_node(void)
{
	t_index_list	*node;

	node = malloc(sizeof(t_index_list));
	if (!node)
		return (NULL);
	return (node);
}
