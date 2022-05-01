/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:40:49 by mariana           #+#    #+#             */
/*   Updated: 2022/05/01 16:09:33 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_item;
	void	*new_content;

	if (!lst)
		return (NULL);
	new_list = NULL;
	new_item = NULL;
	while (lst)
	{
		new_content = (*f)(lst->content);
		new_item = ft_lstnew(new_content);
		if (!new_item)
		{
			ft_lstclear(&new_list, (*del));
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_item);
		lst = lst->next;
	}
	return (new_list);
}
