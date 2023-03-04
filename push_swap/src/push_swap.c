/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:31:48 by mariana           #+#    #+#             */
/*   Updated: 2023/03/04 10:26:23 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_index_stack	*stack_a;
	int				i;
	char			**arguments;

	i = 0;
	if (argc == 2)
		arguments = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		arguments = argv;
	}
	ft_push_swap_valid_args(argc, arguments);
	stack_a = ft_create_stack(ft_atoi(arguments[i]));
	i++;
	while (arguments[i])
	{
		ft_add_to_stack(stack_a, ft_atoi(arguments[i]));
		i++;
	}
	ft_order_stack(&stack_a, stack_a->previous->index + 1);
	ft_delete_stack(&stack_a);
	return (0);
}
