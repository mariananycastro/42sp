/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:01:54 by mariana           #+#    #+#             */
/*   Updated: 2022/04/24 22:46:03 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*s_string;
	unsigned int	sub_len;
	unsigned int	s_len;
	unsigned int	i;

	if (!s)
		return (NULL);
	sub_len = 0;
	s_len = ft_strlen(s);
	if (start < s_len)
	{
		while (s[sub_len + start] && sub_len < len && len != 0)
			sub_len++;
	}
	s_string = (char *) malloc (sizeof(char) * (sub_len + 1));
	if (s_string == NULL)
		return (NULL);
	ft_bzero(s_string, sub_len + 1);
	i = 0;
	while (i < sub_len)
	{
		s_string[i] = s[start + i];
		i++;
	}
	return (s_string);
}
