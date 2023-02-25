/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:31:48 by mariana           #+#    #+#             */
/*   Updated: 2023/02/25 15:29:52 by mariana          ###   ########.fr       */
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

t_index_stack *ft_reverse_rotate_a(t_index_stack *stack_a)
{
	write(1, "rra\n", 4);
	return (ft_reverse_rotate(stack_a));
}

void	ft_push_b(t_index_stack **stack_from, t_index_stack **stack_to)
{
	ft_push(stack_from, stack_to);
	write(1, "pb\n", 3);
}

void	ft_push_a(t_index_stack **stack_from, t_index_stack **stack_to)
{
	ft_push(stack_from, stack_to);
	write(1, "pa\n", 3);
}

int	main(int argc, char *argv[])
{
	t_index_stack	*stack_a;
	int				i;
	int				biggest_number;
	int				max_bits;
	t_index_stack	*stack_b;

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
	int final;
	int z;
	stack_b = NULL;
	i = 0;
	z = 0;
	final = stack_a->previous->index;
	while (i < max_bits)
	{
		while(z <= final)
		{
			if (!((stack_a->position >> i) & 1))
			{
				if (!stack_b)
					stack_b = ft_new_stack(&stack_a);
				else
					ft_push_b(&stack_a, &stack_b);
			}
			else
				stack_a = ft_reverse_rotate_a(stack_a);
			z++;
		}
		while(stack_b)
		{
			ft_push_a(&stack_b, &stack_a);
		}
		z = 0;
		i++;
	}
printf("-----------------------\n");
printf("node a value %d, index %d, position %d\n", stack_a->value, stack_a->index, stack_a->position);
printf("node a value %d, index %d, position %d\n", stack_a->next->value, stack_a->next->index, stack_a->next->position);
printf("node a value %d, index %d, position %d\n", stack_a->next->next->value, stack_a->next->next->index, stack_a->next->next->position);
printf("node a value %d, index %d, position %d\n", stack_a->next->next->next->value, stack_a->next->next->next->index, stack_a->next->next->next->position);
printf("node a value %d, index %d, position %d\n", stack_a->next->next->next->next->value, stack_a->next->next->next->next->index, stack_a->next->next->next->next->position);
printf("node a value %d, index %d, position %d\n", stack_a->next->next->next->next->next->value, stack_a->next->next->next->next->next->index, stack_a->next->next->next->next->next->position);
printf("node a value %d, index %d, position %d\n", stack_a->next->next->next->next->next->next->value, stack_a->next->next->next->next->next->next->index, stack_a->next->next->next->next->next->next->position);
printf("node a value %d, index %d, position %d\n", stack_a->next->next->next->next->next->next->next->value, stack_a->next->next->next->next->next->next->next->index, stack_a->next->next->next->next->next->next->next->position);


	// if (stack_b){
	// 	ft_delete_stack(&stack_b);
	// }

	ft_delete_stack(&stack_a);
	return (0);
}

// ft se a menor ou b menor push todo o resto
// to do remove ft_create_stack and use only add to stack

// testar com negativos e zero
// testar só com numeros par e impar
