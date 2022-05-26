/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:29:55 by mariana           #+#    #+#             */
/*   Updated: 2022/05/25 09:15:09 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest || !src)
		return (NULL);
	while (i < n)
	{
		*(char *)(dest + i) = *(char *)(src + i);
		i++;
	}
	*(char *)(dest + i) = '\0';
	return (NULL);
}

int	ft_strchr(char *s, int c)
{
	size_t	i;
	size_t	size;

	if (!s)
		return (0);
	size = ft_strlen(s);
	i = 0;
	while (i <= size)
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdup(char *src)
{
	char	*copy;
	int		i;
	int		size;

	size = ft_strlen(src);
	copy = (char *) malloc((size + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strappend(char *s1, char *s2)
{
	char	*new_string;
	size_t	len;
	size_t	i;
	size_t	z;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_string = (char *) malloc((len * sizeof(char)));
	if (new_string == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new_string[i] = s1[i];
		i++;
	}
	z = 0;
	while (s2[z])
		new_string[i++] = s2[z++];
	new_string[i] = '\0';
	free(s1);
	return (new_string);
}
