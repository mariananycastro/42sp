unsigned	int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	int answer;
	answer = 0;

	answer = 0;
	while (src[answer])
		answer++;
	if (size == 0)
		return (answer);
	i = 0;
	while (i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[size - 1] = '\0';
	return (answer);
}