/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariana <mariana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 01:35:37 by mcastro           #+#    #+#             */
/*   Updated: 2022/03/30 21:25:18 by mariana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	char	buffer;
	int		fd;

	if (argc < 2)
		write(1, "File name missing.\n", 20);
	else if (argc > 2)
		write(1, "Too many arguments.\n", 21);
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd != -1)
		{
			while (read(fd, &buffer, 1) != 0)
				write(1, &buffer, 1);
		}
		close(fd);
	}
	return (0);
}
