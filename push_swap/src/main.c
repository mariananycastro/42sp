/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:31:48 by mariana           #+#    #+#             */
/*   Updated: 2023/02/11 20:19:31 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
