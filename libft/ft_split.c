#include "libft.h"
#include <stdlib.h>

static void	ft_strcpy(char *dst, char *begin, char *end)
{
	while (begin < end)
		*(dst++) = *(begin++);
	*dst = 0;
}

static int	get_tw(char *s, char c)
{
	int		res;

	res = 0;
	while (*s)
	{
		if (!(*s == c))
		{
			res++;
			while (*s && !(*s == c))
				s++;
		}
		else
			s++;
	}
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	*start;
	char	**res;
	int		i;

	if (!s)
		return (0);
	res = (char **)malloc((sizeof(char *) * (get_tw((char *)s, c) + 1)));
	if (!res)
		return (0);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			start = (char *)s;
			while (*s && *s != c)
				s++;
			res[i] = (char *)malloc((char *)s - start + 1);
			ft_strcpy(res[i++], start, (char *)s);
		}
		else
			s++;
	}
	res[i] = 0;
	return (res);
}
