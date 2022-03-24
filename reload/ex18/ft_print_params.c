#include <unistd.h>

int	main(int argc, char *argv[ ])
{
	int	pointer;
	int	i;

	if (argc > 0)
	{
		pointer = 1;
		i = 0;
		while (argv[pointer])
		{
			while (argv[pointer][i])
			{
				write(1, &argv[pointer][i], 1);
				i++;
			}
			write(1, "\n", 1);
			i = 0;
			pointer++;
		}
	}
	return (0);
}