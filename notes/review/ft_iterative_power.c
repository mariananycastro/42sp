int	ft_iterative_power(int nb, int power)
{
	int	number;
	int	i;

	number = 1;
	i = 0;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
	{
		while (i++ < power)
			number = number * nb;
	}
	return (number);
}