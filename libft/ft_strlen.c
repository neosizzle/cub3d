#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	res;

	res = 0;
	if (!s)
		return (res);
	while (*s != '\0')
	{
		s++;
		res++;
	}
	return (res);
}
