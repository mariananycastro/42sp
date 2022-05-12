/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 13:30:05 by mariana           #+#    #+#             */
/*   Updated: 2022/05/12 19:43:05 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_break_line(int c)
{
	return (c >= 9 && c <= 13);
}

static size_t	ft_buffer_size(char *buffer)
{
	size_t	buffer_size;

	buffer_size = 0;
	while (buffer[buffer_size] && !ft_break_line(buffer[buffer_size]))
		buffer_size++;
	return (buffer_size);
}

static char	*ft_strjoins(char *s1, char *s2, size_t size)
{
	char		*new_string;
	int			len;
	size_t		i;
	size_t		z;

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

static char	*ft_temp(int fd, char *actual_line)
{
	char		*buffer;
	char		*temp_line;
	int			temp_size;
	int			next_size;
	static char	*next_line;
	size_t		buffer_size;

	buffer = (char *) ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	read(fd, buffer, BUFFER_SIZE);
	buffer_size = ft_buffer_size(buffer);
	if (next_line && buffer_size > 0)
	{
		next_size = ft_strlen(next_line);
		actual_line = (char *) ft_calloc((next_size + 1), sizeof(char));
		ft_strlcpy(actual_line, next_line, next_size + 1);
	}
	if (buffer_size > 0)
	{
		temp_size = buffer_size + BUFFER_SIZE + 1;
		temp_line = (char *) ft_calloc(temp_size, sizeof(char));
		temp_line = ft_strjoins(actual_line, buffer, buffer_size);
		temp_size = ft_strlen(temp_line);
		actual_line = (char *) ft_calloc((temp_size + 1), sizeof(char));
		ft_strlcpy(actual_line, temp_line, temp_size + 1);
		if (buffer_size == BUFFER_SIZE)
			actual_line = ft_temp(fd, actual_line);
		else
		{
			next_size = BUFFER_SIZE - buffer_size;
			if (next_size != 1)
			{
				next_line = (char *) ft_calloc(next_size, sizeof(char));
				ft_strlcpy(next_line, &buffer[next_size], next_size);
			}
		}
		return (actual_line);
	}
	else
	{
		next_line = (char *) ft_calloc(BUFFER_SIZE, sizeof(char));
		ft_strlcpy(next_line, &buffer[1], next_size + 1);
	}
	return (actual_line);
}

char	*get_next_line(int fd)
{
	char	*actual_line;

	if ((fd < -1) || BUFFER_SIZE <= 0)
		return (NULL);
	actual_line = (char *) ft_calloc(1, sizeof(char));
	actual_line = ft_temp(fd, actual_line);
	return (actual_line);
}
