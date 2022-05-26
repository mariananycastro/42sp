/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 13:30:05 by mariana           #+#    #+#             */
/*   Updated: 2022/05/25 11:38:18 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	ft_read_file(int fd, char **line)
{
	char	*buffer;
	int		read_bytes;
	int		count;

	buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return ;
	read_bytes = 1;
	count = 0;
	while (count != 1 && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
		{
			free(buffer);
			return ;
		}
		buffer[read_bytes] = '\0';
		count = ft_strchr(buffer, '\n');
		if (!*line)
			*line = ft_strdup(buffer);
		else
			*line = ft_strappend(*line, buffer);
	}
	free(buffer);
}

static int	ft_get_current(char *line, char **current)
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

static void	ft_set_overflow(char **line, int begin_next, char **overflow)
{
	int	len;

	len = ft_strlen(*line);
	if (len != begin_next)
		*overflow = ft_strdup(*line + begin_next);
	free(*line);
}

char	*get_next_line_bonus(int fd)
{
	static char	*overflow[1024];
	char		*line;
	int			current_size;
	char		*current;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (overflow[fd])
	{
		line = ft_strdup(overflow[fd]);
		free(overflow[fd]);
		overflow[fd] = NULL;
	}
	else
		line = NULL;
	ft_read_file(fd, &line);
	if (!line || line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	current_size = ft_get_current(line, &current);
	ft_set_overflow(&line, current_size, &overflow[fd]);
	return (current);
}
