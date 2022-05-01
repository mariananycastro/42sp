/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:15:58 by mariana           #+#    #+#             */
/*   Updated: 2022/04/21 22:46:17 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t	b;
	size_t	l;
	size_t	size_little;

	b = 0;
	l = 0;
	size_little = ft_strlen(little);
	if (size_little == 0)
		return ((char *)(big));
	while (b < len && little[l])
	{
		while (little[l] == big[b] && b < len)
		{
			if (l == size_little - 1)
				return ((char *)big + b - l);
			l++;
			b++;
		}
		l = 0;
		if (little[l] == big[b])
			l++;
		b++;
	}
	return (NULL);
}
