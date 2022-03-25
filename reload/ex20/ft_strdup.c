#include <stdlib.h>
#include <stdio.h>

int	ft_length(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

char *ft_strdup(char *src)
{
	char	*copy;
	int 	i;
	int		size;

	size = ft_length(src);
	copy = (char *) malloc((size) * sizeof(char));
    if (copy == NULL)
    {
        return (NULL);
    }
	i = 0;
	while(src[i])
	{
		copy[i] = src[i];
		i++;
	}
	return (copy);
}
