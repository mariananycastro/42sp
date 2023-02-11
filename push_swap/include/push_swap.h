/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:21:23 by mariana           #+#    #+#             */
/*   Updated: 2023/02/11 20:09:05 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

typedef struct s_index_list
{
	void				*content;
	int					index;
	struct s_index_list	*previous;
	struct s_index_list	*next;
}	t_index_list;

t_index_list	*ft_create_node(void);
t_index_list	*ft_create_lst(void *content);
void			ft_add_to_lst(t_index_list *first_of_lst, void *new_content);
t_index_list	*ft_rotate(t_index_list *first_node);
t_index_list	*ft_reverse_rotate(t_index_list *first_node);
void			ft_swap(t_index_list *first_node);
void			ft_delete_list(t_index_list **node);
t_index_list	*ft_removed_node(t_index_list **node);
t_index_list	*ft_new_list(t_index_list **node);
t_index_list	*ft_push(t_index_list **list_from, t_index_list *list_to);
#endif
