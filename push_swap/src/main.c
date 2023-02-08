/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:31:48 by mariana           #+#    #+#             */
/*   Updated: 2023/02/07 20:59:54 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_index_list    *ft_create_lst(void *content)
{
	t_index_list	*first_item;

	first_item = malloc(sizeof(t_index_list));
	if (!first_item)
		return (NULL);
	first_item->content = content;
	first_item->index = 0;
	first_item->previous = first_item;
	first_item->next = first_item;
	return (first_item);
}

void	ft_add_to_lst(t_index_list *first_of_lst, void *new_content)
{
	t_index_list	*new_node;

	new_node = malloc(sizeof(t_index_list));
	if (!new_node)
		return;

	new_node->content = new_content;
	new_node->index = first_of_lst->previous->index + 1;
	new_node->next = first_of_lst;
	new_node->previous = first_of_lst->previous;
	
	first_of_lst->previous->next = new_node;
	first_of_lst->previous = new_node;
}

void	ft_delete_lst(t_index_list **lst, void (*del)(void*))
{
	t_index_list	*copy;
	t_index_list	*next;

	if (!lst)
		return ;
	copy = *lst;
	while (copy)
	{
		next = copy->next;
		del(copy->content);
		free(copy);
		copy = next;
	}
	*lst = NULL;
}

// int	main(int argc, char *argv[], char *envp[])
int	main(int argc, char *argv[])
{
    t_index_list *first;
	int 		 i;

	i = 1;
    first = ft_create_lst(argv[i]);
	while(i < argc)
	{
		i++;
		ft_add_to_lst(first, argv[i]);
	}

    printf("argc %d\n", argc);
    printf("first %d, %s\n", first->index, first->content);
    printf("second %d, %s\n", first->next->index, first->next->content);
    printf("second %d, %s\n", first->next->next->index, first->next->next->content);

	// deletar lista
	// swap
	// rotate
	// reverse rotate
	// push
    return 0;
}
