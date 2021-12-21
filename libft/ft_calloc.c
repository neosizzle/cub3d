#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*res;
	int		i;

	res = malloc((nelem * elsize));
	if (!res)
		return (0);
	i = 0;
	while ((int)(nelem * elsize) > i)
	{
		*(char *)(res + i) = 0;
		i++;
	}
	return (res);
}
