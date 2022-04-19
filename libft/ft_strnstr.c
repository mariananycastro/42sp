/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:15:58 by mariana           #+#    #+#             */
/*   Updated: 2022/04/19 18:13:45 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	size_little;

	if (!little)
		return ((char *)(big));
	i = 0;
	j = 0;
	size_little = ft_strlen(little);
	while (i < len)
	{
		if (little[j] && big[i] == little[j])
		{
			if ((size_little - 1) == j)
				return ((char *)(big + j - 1));
			j++;
		}
		else
			j = 0;
		i++;
	}
	return (NULL);
}
