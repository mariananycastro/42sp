/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 13:30:05 by mariana           #+#    #+#             */
/*   Updated: 2022/05/22 20:29:23 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_read_file(int fd, char **line, char **overflow)
{
	char	*buffer;
	char	*temp;
	int		read_bytes;

	buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return ;
	read_bytes = 1;
	if (*overflow)
	{
		*line = ft_strdup(*overflow);
		if (!*line)
			return ;
		free(*overflow);
		*overflow = NULL;
	}
	else
		*line = NULL;
	while (!ft_strchr(*line, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
		{
			free(buffer);
			return ;
		}
		buffer[read_bytes] = '\0';
		if (!*line)
			*line = ft_strdup(buffer);
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

int	ft_get_current(char *line, char **current)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	*current = (char *) malloc((i + 1) * sizeof(char));
	if (!current)
		return (0);
	ft_memcpy(*current, line, i);
	return (i);
}

void	ft_set_overflow(char **line, int begin_next, char **overflow)
{
	int	len;

	len = ft_strlen(*line);
	if (len != begin_next)
		*overflow = ft_strdup(*line + begin_next);
	free(*line);
}

char	*get_next_line(int fd)
{
	static char	*overflow;
	char		*line;
	int			current_size;
	char		*current;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_read_file(fd, &line, &overflow);
	if (!line || line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	current_size = ft_get_current(line, &current);
	ft_set_overflow(&line, current_size, &overflow);
	return (current);
}
