/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 13:30:05 by mariana           #+#    #+#             */
/*   Updated: 2022/05/20 21:48:37 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd)
{
	char	*buffer;
	int		read_bytes;

	buffer = (char *) ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	read_bytes = 0;
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (read_bytes <= 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[BUFFER_SIZE] = '\0';
	return (buffer);
}

static char	*aloc_line(int len, char *position)
{
	char	*temp;

	temp = (char *) ft_calloc((len), sizeof(char));
	ft_memcpy(temp, position, len - 1);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*next;
	char		*current;
	char		*buffer;
	int			s;
	int			buffer_len;
	int			bolinha;
	char		*temp_buffer;
	char		*temp_buffer2;

	if ((fd < 1) || BUFFER_SIZE <= 0)
		return (NULL);
	current = NULL;
	if (next)
	{
		s = 0;
		while (next[s] && next[s] != '\n')
			s++;
		if (s == 0)
		{
			buffer_len = ft_strlen(next);
			if (buffer_len > 1)
			{
				temp_buffer = aloc_line(buffer_len, (next + 1));
				free(next);
				next = temp_buffer;
				return (current);
			}
			else
			{
				free(next);
				return (current);
			}
		}
		else
		{
			if (s == BUFFER_SIZE - 1)
			{
				current = aloc_line(BUFFER_SIZE, next);
				free(next);
			}
			else
			{
				current = aloc_line((s + 1), next);
				buffer_len = ft_strlen(next);
				if (buffer_len - s > 1)
				{
					temp_buffer = aloc_line((buffer_len - s), (next + s + 1));
					free(next);
					next = temp_buffer;
				}
				else if (buffer_len - s == 1)
				{
					next = '\0';
					// free(next);
					return (current);
				}
			}
		}
	}
	bolinha = 0;
	while (bolinha == 0)
	{
		buffer = read_file(fd);
		if (!buffer)
			return (current);
		s = 0;
		while (buffer[s] && buffer[s] != '\n')
			s++;
		if (s == BUFFER_SIZE)
		{
			if (current)
			{
				temp_buffer = current;
				current = ft_strjoin(temp_buffer, buffer);
				free(temp_buffer);
				free(buffer);
			}
			else
			{
				current = aloc_line((BUFFER_SIZE + 1), buffer);
				free(buffer);
			}
		}
		else
		{
			if (s == 0 && !current)
			{
				buffer_len = ft_strlen(buffer);
				current = aloc_line(2, buffer);
				if (buffer_len > 1)
					next = aloc_line(buffer_len, (buffer + 1));
				free(buffer);
				return (current);
			}
			else if (s == 0)
			{
				temp_buffer2 = current;
				current = ft_strjoin(temp_buffer2, buffer);
			}
			else
			{
				temp_buffer = aloc_line((s + 1), buffer);
				temp_buffer2 = current;
				current = ft_strjoin(temp_buffer2, temp_buffer);
				free(temp_buffer);
				free(temp_buffer2);
				buffer_len = ft_strlen(buffer);
				if (buffer_len - s > 1)
				{
					next = aloc_line((buffer_len - s), (buffer + s + 1));
					free(buffer);
				}
				else
				{
					free(next);
					free(buffer);
				}
			}
			bolinha++;
		}
	}
	return (current);
}
