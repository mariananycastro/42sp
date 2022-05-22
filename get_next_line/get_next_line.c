/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 13:30:05 by mariana           #+#    #+#             */
/*   Updated: 2022/05/22 18:02:56 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void ft_read_file(int fd, char **line)
{
	char	*buffer;
	char	*temp;
	int		read_bytes;

	buffer = (char *) ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return ;
	read_bytes = 1;
	while (!ft_strchr(*line, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
		{
			// free line
			free(buffer);
			return ;
		}
		buffer[read_bytes] = '\0'; // talvez remover
		if (!*line)
		{
			*line = ft_strdup(buffer);
		}
		else
		{
			temp = ft_strjoin(*line, buffer);
			free(*line);
			*line = temp;
		}
	}
	free(buffer);
	return ;
}

int ft_get_current(char *line, char **current)
{
	int i;

	i = 0;
	while(line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	*current = (char *) ft_calloc((i + 1), sizeof(char));
	if (current)
	{
		ft_memcpy(*current, line, i);
		return (i);	
	}
	return (0);
}

void ft_set_next_line(char **line, int begin_next)
{
	int len;
	char *temp;

	len = ft_strlen(*line);
	if (len >= begin_next)
	{
		temp = (char *) malloc((len - begin_next + 1) * sizeof(char));
		temp = ft_strdup(*line + begin_next);
		free(*line);
		*line = temp;
	}
	else
		free(*line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	int			current_size;
	char		*current;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_read_file(fd, &line);
	if (!line || line[0] == '\0')
	{
		free(line);
		// printf("aquii c = '%s', l = '%s', %p\n", current, line, &current);
		return (NULL);
	}
	current_size = ft_get_current(line, &current);
	ft_set_next_line(&line, current_size);
	// printf("c = '%s','\n", line);
	// printf("c = '%s', l = '%s', %p\n", current, line, current_size);
	return (current);
	// return (NULL);
}
