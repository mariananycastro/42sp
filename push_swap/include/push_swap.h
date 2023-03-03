/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:21:23 by mariana           #+#    #+#             */
/*   Updated: 2023/03/03 20:14:46 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

typedef struct s_index_stack
{
	int						value;
	int						index;
	int						position;
	struct s_index_stack	*previous;
	struct s_index_stack	*next;
}	t_index_stack;

t_index_stack	*ft_create_node(void);
t_index_stack	*ft_create_stack(int value);
void			ft_add_to_stack(t_index_stack *first_of_lst, int new_content);
void			ft_rotate(t_index_stack **first_node);
void			ft_reverse_rotate(t_index_stack **first_node);
void			ft_swap(t_index_stack **first_node);
void			ft_delete_stack(t_index_stack **node);
t_index_stack	*ft_removed_node(t_index_stack **node);
t_index_stack	*ft_new_stack(t_index_stack **node);
void			ft_push(t_index_stack **stack_from, t_index_stack **stack_to);
int				ft_push_swap_valid_args(int argc, char **argv);
int				ft_repeated_input(int current_number, char **argv, int i);
int				ft_isnum(int number, char *arg);
int				ft_set_position(t_index_stack **stack_a);
int				ft_set_order(t_index_stack **stack_a);
void			ft_order_stack(t_index_stack **stack_a, int stack_size);
void			ft_radix_order(t_index_stack **stack_a, int max_bits);
int				ft_is_sorted(t_index_stack **stack);
void			ft_swap_a(t_index_stack **stack_a);
void			ft_swap_b(t_index_stack **stack_b);
int				ft_stack_last_item(t_index_stack *stack_a);
void			ft_rotate_a(t_index_stack **stack_a);
void			ft_reverse_rotate_a(t_index_stack **stack_a);
void			ft_push_b(t_index_stack **stack_b, t_index_stack **stack_a);
void			ft_push_all(t_index_stack **stack_b, t_index_stack **stack_a);
void			ft_push_a(t_index_stack **stack_from, t_index_stack **stack_to);
void			ft_sort_4(t_index_stack **stack);
void			ft_sort_3(t_index_stack **stack);
void			ft_sort_5(t_index_stack **stack);
#endif
