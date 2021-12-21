#include "libft.h"
#include <stdlib.h>

static	int	validate(char const *s, unsigned int start, char *res)
{
	if (start > ft_strlen(s))
	{
		free (res);
		return (0);
	}
	return (1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	int		i;

	res = (char *)malloc(ft_strlen(s) + 1);
	if (!res)
		return (0);
	if (!validate(s, start, res))
		return (ft_strdup("\0"));
	while (start--)
	{
		if (!(*s++))
		{
			free(res);
			return (ft_strdup("\0"));
		}
	}
	i = 0;
	while (len && *s)
	{
		res[i++] = (*s++);
		len--;
	}
	res[i] = 0;
	return (res);
}
