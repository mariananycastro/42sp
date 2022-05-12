/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 13:30:05 by mariana           #+#    #+#             */
/*   Updated: 2022/05/11 23:45:40 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


#include <stdio.h>

int	ft_break_line(int c)
{
	return (c >= 9 && c <= 13);
}

int	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2, size_t size)
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
	while (s2[z] && z < size)
		new_string[i++] = s2[z++];
	new_string[i] = '\0';
	return (new_string);
}

unsigned	int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	int				answer;

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

char *ft_temp(int fd, char *actual_line)
{
    char *buffer;
    char *temp_line;
    size_t buffer_size;
    int temp_size;
	size_t next_size;
	static char *next_line;

    buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buffer)
        return (NULL);
    read(fd, buffer, BUFFER_SIZE);
	buffer_size = 0;
	while(buffer[buffer_size] && !ft_break_line(buffer[buffer_size]))
		buffer_size++;
	if (next_line && buffer_size > 0)
	{
		next_size = ft_strlen(next_line);
		actual_line = (char *) malloc((next_size + 1) * sizeof(char));
        if (!actual_line)
            return (NULL);
        ft_strlcpy(actual_line, next_line, next_size + 1);
	}
    if (buffer_size > 0)
    {
        temp_line = (char *) malloc((buffer_size + BUFFER_SIZE + 1) * sizeof(char));
        if (!temp_line)
            return (NULL);
        temp_line = ft_strjoin(actual_line, buffer, buffer_size);
        temp_size = ft_strlen(temp_line);
        actual_line = (char *) malloc((temp_size + 1) * sizeof(char));
        if (!actual_line)
            return (NULL);
        ft_strlcpy(actual_line, temp_line, temp_size + 1);
		if (buffer_size == BUFFER_SIZE)
			actual_line = ft_temp(fd, actual_line);
		else
		{
			next_size = BUFFER_SIZE - buffer_size;
			if (next_size != 1)
			{
				next_line = (char *) malloc(next_size * sizeof(char));
				if (!next_line)
					return (NULL);
				ft_strlcpy(next_line, &buffer[next_size], BUFFER_SIZE - buffer_size);
			}
		}
		return (actual_line);
    }
	else
	{
		next_line = (char *) malloc((BUFFER_SIZE) * sizeof(char));
		if (!next_line)
			return (NULL);
		ft_strlcpy(next_line, &buffer[1], next_size + 1);
	}
    return (actual_line);
}

char *get_next_line(int fd)
{
    char *actual_line;

    if ((fd < -1) || BUFFER_SIZE <= 0)
        return (NULL);
    actual_line = (char *) malloc(sizeof(char));
    if (!actual_line)
        return(NULL);

    actual_line = ft_temp(fd, actual_line);
    return (actual_line);
}