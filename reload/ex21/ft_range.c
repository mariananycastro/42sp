#include <stdlib.h>

int *ft_range(int min, int max)
{
	int	*answer;
	int	i;

	if (min >= max)
		return ((void*)0);
	answer = (int *) malloc((max - min)* sizeof(int));
	i = 0;
	while (min < max)
	{
		answer[i] = min;
		i++;
		min++;
	}
	return (answer);
}
