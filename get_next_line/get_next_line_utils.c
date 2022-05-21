/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:29:55 by mariana           #+#    #+#             */
/*   Updated: 2022/05/20 21:50:01 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (i < n)
	{
		*(char *)(s + i) = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*alloc_nmemb;
	long int	copy_size;
	long int	copy_nmemb;

	copy_size = size;
	copy_nmemb = nmemb;
	if (copy_nmemb <= 0 || copy_size <= 0)
		return (NULL);
	alloc_nmemb = malloc (nmemb * size);
	if (!alloc_nmemb)
		return (NULL);
	ft_bzero(alloc_nmemb, nmemb * size);
	return (alloc_nmemb);
}

int	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

// procura em n bytes de s pela primeira ocorrencia de c 
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	if (!s)
		return (NULL);
	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return (str + i);
		i++;
	}
	return (NULL);
}

// copia n data de *src p *dest
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

// localiza c na string e retorna primeira ocorrencia;
char	*ft_strchr(char *s, int c)
{
	size_t	i;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	i = 0;
	while (i <= size)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

// return copia de src
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

// return nova string concatenando s1 e s2
char	*ft_strjoin(char *s1, char *s2)
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
	return (new_string);
}

// copia strings
unsigned	int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	int				answer;

	answer = 0;
	answer = ft_strlen(src);
	if (size == 0)
		return (answer);
	i = 0;
	while (src[i] && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (answer);
}
