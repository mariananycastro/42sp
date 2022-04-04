/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 13:49:28 by mariana           #+#    #+#             */
/*   Updated: 2022/04/03 20:09:49 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_c(char const *s, char c)
{
	size_t	count_c;
	size_t	i;

	i = 0;
	count_c = 0;
	while (s[i])
	{
		if (s[i++] == c)
			count_c++;
	}
	return (count_c);
}

static int	ft_set_str(char const *s, char **array, size_t array_index, size_t begin_string, size_t count_letters)
{
	array[array_index] = ft_substr(s, begin_string, count_letters + 1);
	if (!array[array_index])
	{
		free(array[array_index]);
		return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	begin_string;
	size_t	array_index;
	size_t	count_letters;
	size_t	i;

	array = (char **) malloc(sizeof(s) * (ft_count_c(s, c) + 1));
	if (!array)
		return (NULL);
	i = 0;
	begin_string = 0;
	array_index = 0;
	count_letters = 0;
	while (s[i])
	{
		if (s[i] == c && count_letters != 0)
		{
			if (ft_set_str(s, array, array_index, begin_string, count_letters))
				array_index++;
			count_letters = 0;
			begin_string = i + 1;
		}
		if (s[i] != c)
			count_letters++;
		i++;
	}
	if (count_letters != 0)
		ft_set_str(s, array, array_index, begin_string, count_letters);
	array[array_index + 1] = '\0';
	return (array);
}
