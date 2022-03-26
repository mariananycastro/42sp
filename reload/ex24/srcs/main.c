#include "../includes/header.h"

void	ft_print(int argc, char *argv[ ])
{
	int	pointer;

	if (argc > 0)
	{
		pointer = 1;
		while (argv[pointer])
		{
			ft_putstr(argv[pointer]);
			write (1, "\n", 1);
			pointer++;
		}
	}
}

int	main(int argc, char *argv[ ])
{
	int		z;
	int		i;
	int		result;

	z = 1;
	if (argc > 0)
	{
		while (z < (argc - 1))
		{
			i = 1;
			while (i < (argc - 1))
			{
				result = ft_strcmp(argv[i], argv[i + 1]);
				if (result > 0)
        // TO DO fix swap
					ft_swap(&argv[i], &argv[i + 1]);
				i++;
			}
			z++;
		}
		ft_print(argc, argv);
	}
	return (0);
}
