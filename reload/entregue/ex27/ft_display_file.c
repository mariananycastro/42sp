/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcastro <mariananycastro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 01:35:37 by mcastro           #+#    #+#             */
/*   Updated: 2022/03/28 01:36:25 by mcastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	char	buffer;
	int		fd;

	if (argc != 2)
	{
		if (argc < 2)
			write(1, "File name missing.\n", 20);
		else if (argc > 2)
			write(1, "Too many arguments.\n", 21);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	while (read(fd, &buffer, 1) != 0)
		write(1, &buffer, 1);
	close(fd);
	return (0);
}
