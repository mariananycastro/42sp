#include <unistd.h>

void	ft_write_number(int n)
{
	int	number;

	number = n + 48;
	write(1, &number, 1);
}

void	ft_putnbr(int nb)
{
	long	tmp_number;
	char	positive_number;

	tmp_number = nb;
	if (tmp_number < 0)
	{
		write(1, "-", 1);
		tmp_number = tmp_number * -1;
	}
	if (tmp_number >= 10)
		ft_putnbr(tmp_number / 10);
	positive_number = (tmp_number % 10);
	ft_write_number(positive_number);
}