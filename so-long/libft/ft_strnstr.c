/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:15:58 by mariana           #+#    #+#             */
/*   Updated: 2022/08/21 16:49:24 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t	b;
	size_t	l;

	b = 0;
	if (!little[b])
		return ((char *) big);
	while (big[b])
	{
		l = 0;
		while (big[b + l] == little[l] && little[l] && b + l < len)
			l++;
		if (!little[l])
			return ((char *) big + b);
		b++;
	}
	return (NULL);
}
