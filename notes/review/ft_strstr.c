unsigned int	ft_strlen(char *dest)
{
	unsigned int	i;

	i = 0;
	while (dest[i])
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	to_find_len;
	unsigned int	i;
	unsigned int	j;

	to_find_len = ft_strlen(to_find);
	i = 0;
	if (to_find_len == 0)
		return (str);
	while (str[i])
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			if (j == (to_find_len - 1))
				return (str + i);
			j++;
		}
		i++;
	}
	return (0);
}
