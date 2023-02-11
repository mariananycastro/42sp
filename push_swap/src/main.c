/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:31:48 by mariana           #+#    #+#             */
/*   Updated: 2023/02/11 18:24:17 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_index_list	*ft_create_node(void)
{
	t_index_list	*node;

	node = malloc(sizeof(t_index_list));
	if (!node)
		return (NULL);
	return (node);
}

t_index_list    *ft_create_lst(void *content)
{
	t_index_list	*first_item;

	if (!content)
		return (NULL);
	first_item = ft_create_node();
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

	if (!first_of_lst || !new_content)
		return ;
	new_node = ft_create_node();
	if (!new_node)
		return ;
	new_node->content = new_content;
	new_node->index = first_of_lst->previous->index + 1;
	new_node->next = first_of_lst;
	new_node->previous = first_of_lst->previous;
	
	first_of_lst->previous->next = new_node;
	first_of_lst->previous = new_node;
}

t_index_list	*ft_rotate(t_index_list *first_node)
{
	int				i;
	int				end;
	t_index_list	*next_node;

	if (!first_node)
		return (NULL);
	i = 0;
	end = first_node->previous->index;
	next_node = first_node->previous;
	while(next_node && i <= end)
	{
		next_node->index = i;
		next_node = next_node->next;
		i++;
	}

	ft_printf("r");
	return (first_node->previous);
}

t_index_list	*ft_reverse_rotate(t_index_list *first_node)
{
	int				i;
	t_index_list	*next_node;

	if (!first_node)
		return (NULL);
	i = first_node->index;
	first_node->index = first_node->previous->index;
	next_node = first_node->next;
	while(next_node && i <= next_node->index)
	{
		next_node->index = i;
		next_node = next_node->next;
		i++;
	}
	ft_printf("rr");
	return (first_node->next);
}

void	ft_swap(t_index_list *first_node)
{
	void *content_copy;

	content_copy = first_node->content;
	first_node->content = first_node->next->content;
	first_node->next->content = content_copy;
	ft_printf("s");
}

void	ft_delete_node(t_index_list **node)
{
	t_index_list	*temp;
	t_index_list	*next_node;
	int				i;

	if(!*node)
		return ;
	temp = *node;
	if(!temp)
		return ;
	temp->previous->next = temp->next;
	temp->next->previous = temp->previous;
	*node = temp->next;
	next_node = temp->next;
	i = 0;
	while(temp && i < next_node->index)
	{
		next_node->index = i;
		next_node = next_node->next;
		i++;
	}
	free(temp);
}

void	ft_delete_list(t_index_list **node)
{
	t_index_list	*current;
	t_index_list	*next;
	int				i;
	int				end;

	current = *node;
	if (!node)
		return ;
	i = 0;
	end = current->previous->index;
	while(current && i <= end)
	{
		next = current->next;
		free(current);
		current = next;
		i++;
	}
}

// int	main(int argc, char *argv[], char *envp[])
int	main(int argc, char *argv[])
{
    t_index_list *list_a;
	int 		 i;

	i = 1;
    list_a = ft_create_lst(argv[i]);
	while(i < argc)
	{
		i++;
		ft_add_to_lst(list_a, argv[i]);
	}

    printf("argc %d\n", argc);
    // printf("%s\n", list_a->content);
    // printf("%s\n", list_a->next->content);
    // printf("%s\n", list_a->next->next->content);
    // printf("%s\n", list_a->next->next->next->content);
    // printf("%s\n", list_a->next->next->next->next->content);
    // printf("%s\n", list_a->next->next->next->next->next->content);
    // printf("%s\n", list_a->next->next->next->next->next->next->content);
    // printf("%s\n", list_a->next->next->next->next->next->next->next->content);

	printf("---------\n");
	// printf("%p - %p\n", &list_a, list_a);
    // printf("%d - %s\n", list_a->index, list_a->content);
    // printf("%d - %s\n", list_a->next->index, list_a->next->content);
    // printf("%d - %s\n", list_a->next->next->index, list_a->next->next->content);
    // printf("%d - %s\n", list_a->next->next->next->index, list_a->next->next->next->content);
    // printf("%d - %s\n", list_a->next->next->next->next->index, list_a->next->next->next->next->content);
    // printf("%d - %s\n", list_a->next->next->next->next->next->index, list_a->next->next->next->next->next->content);
    // printf("%d - %s\n", list_a->next->next->next->next->next->next->index, list_a->next->next->next->next->next->next->content);
    // printf("%d - %s\n", list_a->next->next->next->next->next->next->next->index, list_a->next->next->next->next->next->next->next->content);

	ft_delete_list(&list_a);
	// push
    return 0;
}
