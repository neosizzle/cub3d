#include "libft.h"

//allocates mem with size and fills it with zero
char	*ft_bzero(size_t size)
{
	char	*res;
	size_t	i;

	res = (char *)malloc(sizeof(char) * (size + 1));
	if (!res)
		return (0);
	i = 0;
	while (i < size + 1)
	{
		*(char *)(res + i) = 0;
		i++;
	}
	return (res);
}
