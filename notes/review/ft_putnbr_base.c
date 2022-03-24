#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_change_to_base(int nbr, int base_number, char *char_base)
{
	long	temp;

	temp = nbr;
	if (temp < 0)
	{
		ft_putchar('-');
		temp = temp * -1;
	}
	if (temp >= base_number)
		ft_change_to_base(temp / base_number, base_number, char_base);
	ft_putchar(char_base[temp % base_number]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	size;
	int	i;

	size = 0;
	i = 1;
	while (base[size])
	{
		if (base[size] == 43 || base[size] == 45)
			return ;
		while (base[i])
		{
			if (base[size] == base[i])
				return ;
			i++;
		}
		size++;
	}
	if (size == 0 || size == 1)
		return ;
	return (ft_change_to_base(nbr, size, base));
}