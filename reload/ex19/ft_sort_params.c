#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_print(int argc, char *argv[ ])
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
			write (1, "\n", 1);
			i = 0;
			pointer++;
		}
	}
}

void	ft_swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
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
					ft_swap(&argv[i], &argv[i + 1]);
				i++;
			}
			z++;
		}
		ft_print(argc, argv);
	}
	return (0);
}
