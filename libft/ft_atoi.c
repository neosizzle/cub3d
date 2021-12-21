int	ft_atoi(const char *nptr)
{
	int	polarity;
	int	res;

	polarity = 1;
	res = 0;
	while (*nptr == 9 || *nptr == 32 || *nptr == '\n'
		|| *nptr == '\t' || *nptr == '\r' || *nptr == '\v'
		|| *nptr == '\f')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			polarity *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		res *= 10;
		res += (int)(*nptr - '0');
		nptr++;
	}
	return (res * polarity);
}
