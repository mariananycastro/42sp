void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	z;
	int	temp;

	z = 0;
	while (z < size)
	{
		i = 0;
		while (i < size)
		{
			if (tab[i] > tab[i + 1])
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
			}
			i++;
		}
		z++;
	}
}
