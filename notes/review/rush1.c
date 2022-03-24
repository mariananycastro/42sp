#include <unistd.h>

void	temp2(int y, char *char_letter);
void	rush(int x, int y);

int	main(void)
{
	rush(10, 5);
	return (0);
}

void	rush(int x, int y)
{
	char	letters[2];
	char	*char_letter;
	int		f;

	char_letter = letters;
	f = 1;
	while (f <= x)
	{
		if (f == 1)
			char_letter = "AB";
		else if (f == x)
			char_letter = "CB";
		else
			char_letter = "B ";
		temp2(y, char_letter);
		f++;
	}
	write (1, "\n", 1);
}

void	temp2(int y, char *char_letter)
{
	int	i;

	i = 1;
	while (i <= y)
	{
		if (i == 1 || i == y)
			write (1, &char_letter[0], 1);
		else
			write (1, &char_letter[1], 1);
		i++;
	}
	write (1, "\n", 1);
}