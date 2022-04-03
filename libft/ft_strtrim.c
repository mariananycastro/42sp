/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:42:48 by mariana           #+#    #+#             */
/*   Updated: 2022/04/03 19:53:08 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_has_set(char const *s1, int index, char const *set, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (s1[index] == set[i])
		{
			index++;
			i++;
		}
		else
			return (0);
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s1_copy;
	size_t	set_len;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	set_len = ft_strlen(set);
	if (ft_has_set(s1, 0, set, set_len))
		start = set_len;
	if (ft_has_set(s1, (ft_strlen(s1) - set_len), set, set_len))
		end = end - set_len;
	s1_copy = (char *) malloc(sizeof(char) * (end - start));
	if (!s1_copy)
		return (NULL);
	i = 0;
	while (start < end)
		s1_copy[i++] = s1[start++];
	s1_copy[i] = 0;
	return (s1_copy);
}
