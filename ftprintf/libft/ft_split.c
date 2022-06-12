/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 13:49:28 by mariana           #+#    #+#             */
/*   Updated: 2022/06/12 12:39:22 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	words;
	int	counter;

	words = 0;
	counter = 0;
	while (*s != '\0')
	{
		if (*s == c)
			counter = 0;
		if (*s != c)
		{
			if (counter == 0)
			{
				words++;
				counter++;
			}
		}
		s++;
	}
	return (words);
}

static char	*ft_set_word(char const*s, int start, int size)
{
	char	*word;
	int		i;

	word = (char *) malloc(sizeof(char) * size);
	if (!word)
		return (NULL);
	i = 0;
	while (i < size - 1)
	{
		word[i] = s[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**ft_alloc_words(char const *s, char c, char **array, size_t size)
{
	size_t		index;
	size_t		i;
	size_t		word_len;

	index = 0;
	word_len = 0;
	i = 0;
	while (index < size && size > 0)
	{
		if (s[i] == c || !s[i])
		{
			if (word_len > 0)
			{
				array[index] = ft_set_word(s, (i - word_len), word_len + 1);
				word_len = 0;
				index++;
			}
		}
		else
			word_len++;
		i++;
	}
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		count_words;

	if (!s)
		return (NULL);
	count_words = ft_count_words(s, c);
	array = (char **) malloc ((count_words + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	array = ft_alloc_words(s, c, array, count_words);
	array[count_words] = NULL;
	return (array);
}
