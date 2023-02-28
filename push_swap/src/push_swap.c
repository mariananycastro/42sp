/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:31:48 by mariana           #+#    #+#             */
/*   Updated: 2023/02/28 20:27:50 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_index_stack	*stack_a;
	int				i;

	ft_push_swap_valid_args(argc, argv);
	i = 1;
	stack_a = ft_create_stack(ft_atoi(argv[i]));
	i++;
	while (i < argc)
	{
		ft_add_to_stack(stack_a, ft_atoi(argv[i]));
		i++;
	}
	ft_order_stack(&stack_a, argc - 1);
	ft_delete_stack(&stack_a);
	return (0);
}
