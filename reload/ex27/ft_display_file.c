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

