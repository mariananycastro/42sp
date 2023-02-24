/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:31:48 by mariana           #+#    #+#             */
/*   Updated: 2023/02/24 15:36:23 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	is_sorted(t_index_stack **stack)
{
	t_index_stack	*tmp;

	tmp = *stack;
	while (tmp->next && tmp->index < tmp->next->index)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void ft_swap_a(t_index_stack *stack_a)
{
	ft_swap(stack_a);
	write(1, "sa\n", 3);
}

void ft_rotate_a(t_index_stack stack_a)
{
	ft_rotate(&stack_a);
	write(1, "ra\n", 3);
}

void ft_reverse_rotate_a(t_index_stack *stack_a)
{
	ft_reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

// void ft_sort_three(t_index_stack *stack_a)
// {
// 	int				bigger_num;
// 	t_index_stack	*tmp_stack;

// 	tmp_stack = stack_a;
// 	bigger_num = tmp_stack->value;
// 	while (tmp_stack && tmp_stack->index < tmp_stack->next->index)
// 	{
// 		if (tmp_stack->value > bigger_num)
// 			bigger_num = tmp_stack->value;
// 		tmp_stack = tmp_stack->next;
// 	}
// 	printf("bigger %d\n", bigger_num);
// 	printf("stack %d\n", (stack_a)->value);
// 	printf("stack %d\n", (stack_a)->next->value);
// 	printf("stack %d\n", (stack_a)->previous->value);
// 	if ((stack_a)->value == bigger_num)
// 		stack_a = ft_reverse_rotate_a(stack_a);
// 	printf("stack %d\n", (stack_a)->value);
// 	printf("stack %d\n", (stack_a)->next->value);
// 	printf("stack %d\n", (stack_a)->previous->value);
// 	if ((stack_a)->next->value == bigger_num)
// 		ft_rotate_a(*stack_a);
// 	//print_stack_a(stack_a);
// 	if ((stack_a)->value > (stack_a)->next->value)
// 		ft_swap(stack_a);
// }

// void ft_sort_radix(t_index_stack *stack_a)
// {
// // se não for sortido faz o q?
// }

void	ft_order_stack(t_index_stack **stack_a, int stack_size)
{

	if (is_sorted(stack_a))
		return ;
	else if (stack_size == 2)
		ft_swap_a(*stack_a);
	else if (stack_size == 3)
		printf("3 numbers\n");
	else
		printf("more than 3 numbers\n");
}


int	main(int argc, char *argv[])
{
	t_index_stack	*stack_a;
	int				i;
	int				biggest_number;
	int				max_bits;

	ft_push_swap_valid_args(argc, argv);
	i = 1;
	stack_a = ft_create_stack(ft_atoi(argv[i]));

	i++;
	while (i < argc)
	{
		ft_add_to_stack(stack_a, ft_atoi(argv[i]));
		i++;
	}
	biggest_number = ft_set_order(&stack_a);
	max_bits = ft_get_max_bits(biggest_number);

	// printf("%d, %d\n", biggest_number, max_bits);

	ft_delete_stack(&stack_a);
	return (0);
}

// ft to create stack b and push value with 0 in poistion
// ft se a menor ou b menor push todo o resto

// to do remove ft_create_stack and use only add to stack
