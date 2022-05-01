/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:42:48 by mariana           #+#    #+#             */
/*   Updated: 2022/04/23 20:17:12 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_search_start(char const *s1, char const *set)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	while (s1[i] && set[z])
	{
		while (set[z])
		{
			if (set[z] == s1[i])
			{
				z = 0;
				i++;
			}
			else
				z++;
		}
	}
	return (i);
}

static int	ft_search_end(char const *s1, char const *set, int index)
{
	int	z;

	z = 0;
	while (s1[index] && set[z])
	{
		while (set[z])
		{
			if (set[z] == s1[index])
			{
				z = 0;
				index--;
			}
			else
				z++;
		}
	}
	return (index);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s1_copy;
	int		start;
	int		end;
	int		i;
	int		mem;

	if (!s1 || !set)
		return (NULL);
	start = ft_search_start(s1, set);
	end = ft_search_end(s1, set, (ft_strlen(s1) - 1));
	mem = (end - start + 2);
	if (mem < 0)
		mem = 1;
	s1_copy = (char *) malloc(sizeof(char) * mem);
	if (!s1_copy)
		return (NULL);
	i = 0;
	if (mem > 1)
	{
		while (start <= end)
			s1_copy[i++] = s1[start++];
	}
	s1_copy[i] = '\0';
	return (s1_copy);
}
