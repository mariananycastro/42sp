/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:31:48 by mariana           #+#    #+#             */
/*   Updated: 2023/02/11 19:55:23 by mariana          ###   ########.fr       */
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

t_index_list	*ft_removed_node(t_index_list **node)
{
	t_index_list	*node_copy;
	t_index_list	*next_node;
	int				i;

	if(!*node)
		return (NULL);
	node_copy = *node;
	if(!node_copy)
		return (NULL);
	node_copy->previous->next = node_copy->next;
	node_copy->next->previous = node_copy->previous;
	*node = node_copy->next;
	next_node = node_copy->next;
	i = 0;
	while(node_copy && i < next_node->index)
	{
		next_node->index = i;
		next_node = next_node->next;
		i++;
	}
	return(node_copy);
}

t_index_list	*ft_new_list(t_index_list **node)
{
	t_index_list	*new_list;

	new_list = ft_removed_node(node);
	new_list->next = new_list;
	new_list->previous = new_list;
	new_list->index = 0;
	return(new_list);
}

t_index_list	*ft_push(t_index_list **list_from, t_index_list *list_to)
{
	t_index_list	*new_node;
	t_index_list	*next_node;
	int				i;
	int				end;

	new_node = ft_removed_node(list_from);
	end = list_to->previous->index + 1;
	list_to->previous->next = new_node;
	new_node->previous = list_to->previous;
	new_node->next = list_to;
	list_to->previous = new_node;
	next_node = new_node;
	i = 0;
	while(new_node && i <= end)
	{
		next_node->index = i;
		next_node = next_node->next;
		i++;
	}
	return(new_node);
}

// int	main(int argc, char *argv[], char *envp[])
int	main(int argc, char *argv[])
{
    t_index_list *list_a;
    t_index_list *list_b;
	int 		 i;

	i = 1;
    list_a = ft_create_lst(argv[i]);
	while(i < argc)
	{
		i++;
		ft_add_to_lst(list_a, argv[i]);
	}

	list_b = ft_new_list(&list_a);
	list_b = ft_push(&list_a, list_b);

    printf("argc %d\n", argc);
	printf("---------\n");
	printf("list_a\n");
    printf("%d - %s\n", list_a->index, list_a->content);
    printf("%d - %s\n", list_a->next->index, list_a->next->content);
    printf("%d - %s\n", list_a->next->next->index, list_a->next->next->content);
    printf("%d - %s\n", list_a->next->next->next->index, list_a->next->next->next->content);
    printf("%d - %s\n", list_a->next->next->next->next->index, list_a->next->next->next->next->content);
    printf("%d - %s\n", list_a->next->next->next->next->next->index, list_a->next->next->next->next->next->content);
    printf("%d - %s\n", list_a->next->next->next->next->next->next->index, list_a->next->next->next->next->next->next->content);
    printf("%d - %s\n", list_a->next->next->next->next->next->next->next->index, list_a->next->next->next->next->next->next->next->content);

	printf("---------\n");
	printf("list_b\n");
	printf("%d - %s\n", list_b->index, list_b->content);
    printf("%d - %s\n", list_b->next->index, list_b->next->content);
    printf("%d - %s\n", list_b->next->next->index, list_b->next->next->content);
    printf("%d - %s\n", list_b->next->next->next->index, list_b->next->next->next->content);
    printf("%d - %s\n", list_b->next->next->next->next->index, list_b->next->next->next->next->content);
    printf("%d - %s\n", list_b->next->next->next->next->next->index, list_b->next->next->next->next->next->content);
    printf("%d - %s\n", list_b->next->next->next->next->next->next->index, list_b->next->next->next->next->next->next->content);
    printf("%d - %s\n", list_b->next->next->next->next->next->next->next->index, list_b->next->next->next->next->next->next->next->content);

	list_b = ft_push(&list_a, list_b);

	printf("list_b\n");
	printf("%d - %s\n", list_b->index, list_b->content);
    printf("%d - %s\n", list_b->next->index, list_b->next->content);
    printf("%d - %s\n", list_b->next->next->index, list_b->next->next->content);
    printf("%d - %s\n", list_b->next->next->next->index, list_b->next->next->next->content);
    printf("%d - %s\n", list_b->next->next->next->next->index, list_b->next->next->next->next->content);
    printf("%d - %s\n", list_b->next->next->next->next->next->index, list_b->next->next->next->next->next->content);
    printf("%d - %s\n", list_b->next->next->next->next->next->next->index, list_b->next->next->next->next->next->next->content);
    printf("%d - %s\n", list_b->next->next->next->next->next->next->next->index, list_b->next->next->next->next->next->next->next->content);

	ft_delete_list(&list_a);
	ft_delete_list(&list_b);
    return 0;
}
