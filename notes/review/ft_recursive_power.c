int	ft_recursive_power(int nb, int power)
{
	int	number;

	number = nb;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
		number = number * ft_recursive_power(number, power - 1);
	return (number);
}
