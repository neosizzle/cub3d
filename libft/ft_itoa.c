#include <stdlib.h>

int	get_len(long nb)
{
	int	res;

	res = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb *= -1;
		res++;
	}
	while (nb > 0)
	{
		nb /= 10;
		res++;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;
	long	ln;

	i = get_len(n);
	ln = n;
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (!res)
		return (0);
	res[i--] = 0;
	if (!ln)
		res[i] = '0';
	if (ln < 0)
	{
		res[0] = '-';
		ln = ln * -1;
	}
	while (ln > 0)
	{
		res[i--] = ln % 10 + '0';
		ln /= 10;
	}
	return (res);
}
