/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:31:48 by mariana           #+#    #+#             */
/*   Updated: 2023/02/23 11:44:45 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int is_sorted(t_index_stack *stack)
{
    while (stack->next)
    {
        if (stack->content > stack->next->content)
            return (0);
        stack = stack->next;
    }
    return (1);
}

// int	main(int argc, char *argv[], char *envp[])
int	main(int argc, char *argv[])
{
    ft_push_swap_valid_args(argc, argv);
    printf("bolinha");
    // t_index_stack *stack_a;
    // t_index_stack *stack_b;
	// int 		 i;

    // i = is_integer(argv[1]);
    // printf("tamanho '%d'\n" , i);

    // if (! is_integer(argv[1]) || ! is_duplicate(argc,argv))
    //     ft_printf("Error\n");
    // stack_a = ft_create_lst(argv[i]);
	// while(i < argc)
	// {
	// 	i++;
	// 	ft_add_to_lst(stack_a, argv[i]);
	// }

	// stack_b = ft_new_stack(&stack_a);
	// stack_b = ft_push(&stack_a, stack_b);

    // printf("argc %d\n", argc);
	// printf("---------\n");
	// printf("stack_a\n");
    // printf("%d - %s\n", stack_a->index, stack_a->content);
    // printf("%d - %s\n", stack_a->next->index, stack_a->next->content);
    // printf("%d - %s\n", stack_a->next->next->index, stack_a->next->next->content);
    // printf("%d - %s\n", stack_a->next->next->next->index, stack_a->next->next->next->content);
    // printf("%d - %s\n", stack_a->next->next->next->next->index, stack_a->next->next->next->next->content);
    // printf("%d - %s\n", stack_a->next->next->next->next->next->index, stack_a->next->next->next->next->next->content);
    // printf("%d - %s\n", stack_a->next->next->next->next->next->next->index, stack_a->next->next->next->next->next->next->content);
    // printf("%d - %s\n", stack_a->next->next->next->next->next->next->next->index, stack_a->next->next->next->next->next->next->next->content);

	// printf("---------\n");
	// printf("stack_b\n");
	// printf("%d - %s\n", stack_b->index, stack_b->content);
    // printf("%d - %s\n", stack_b->next->index, stack_b->next->content);
    // printf("%d - %s\n", stack_b->next->next->index, stack_b->next->next->content);
    // printf("%d - %s\n", stack_b->next->next->next->index, stack_b->next->next->next->content);
    // printf("%d - %s\n", stack_b->next->next->next->next->index, stack_b->next->next->next->next->content);
    // printf("%d - %s\n", stack_b->next->next->next->next->next->index, stack_b->next->next->next->next->next->content);
    // printf("%d - %s\n", stack_b->next->next->next->next->next->next->index, stack_b->next->next->next->next->next->next->content);
    // printf("%d - %s\n", stack_b->next->next->next->next->next->next->next->index, stack_b->next->next->next->next->next->next->next->content);

	// stack_b = ft_push(&stack_a, stack_b);

	// printf("stack_b\n");
	// printf("%d - %s\n", stack_b->index, stack_b->content);
    // printf("%d - %s\n", stack_b->next->index, stack_b->next->content);
    // printf("%d - %s\n", stack_b->next->next->index, stack_b->next->next->content);
    // printf("%d - %s\n", stack_b->next->next->next->index, stack_b->next->next->next->content);
    // printf("%d - %s\n", stack_b->next->next->next->next->index, stack_b->next->next->next->next->content);
    // printf("%d - %s\n", stack_b->next->next->next->next->next->index, stack_b->next->next->next->next->next->content);
    // printf("%d - %s\n", stack_b->next->next->next->next->next->next->index, stack_b->next->next->next->next->next->next->content);
    // printf("%d - %s\n", stack_b->next->next->next->next->next->next->next->index, stack_b->next->next->next->next->next->next->next->content);

	// ft_delete_stack(&stack_a);
	// ft_delete_stack(&stack_b);
    return 0;
}
