
void *ft_memchr(const void *s, int c, size_t n)
{
    size_t i;
    unsigned char *str;

    if (!s)
        return (NULL);
    i = 0;
    str = (unsigned char *)s;
    while (i < n)
    {
        if (str[i] == (unsigned char)c)
            return (str + i);
        i++;
    }
    return (NULL);
}


void *ft_memset(void *s, int c, size_t n)
{
	size_t i;

	if (!s)
		return (NULL);
	i = 0;
	while (i < n)
	{   
        ((unsigned char *)s)[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	i = 0;
	while (i <=  size)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}
