int	ft_iterative_factorial(int nb)
{
	int	answer;
	int	i;

	if (nb < 0)
		return (0);
	i = 1;
	answer = 1;
	while (nb >= i)
	{
		answer = answer * nb;
		nb--;
	}
	return (answer);
}
