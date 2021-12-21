#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!(unsigned char *) src && !(unsigned char *) dst)
		return (NULL);
	if ((unsigned char *) src < (unsigned char *) dst)
	{
		while (++i <= n)
			((unsigned char *) dst)[n - i] = ((unsigned char *) src)[n - i];
	}
	else
	{
		while (i < n)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char dest[] = "asdfg";
  	const char src[]  = "newstring";

	char dest1[] = "asdfg";
  	const char src1[]  = "newstring";

	printf("Before memmove dest = %s, src = %s\n", dest, src);
	memmove(dest, src, 3);
	printf("After memmove dest = %s, src = %s\n", dest, src);

	printf("Before ft_memmove dest = %s, src = %s\n", dest1, src1);
	ft_memmove(dest1, src1, 3);
	printf("After ft_memmove dest = %s, src = %s\n", dest1, src1);

	//printf("%zu %zu\n", (size_t) dest1, (size_t)dest);
	//printf("%zd\n" ,(size_t) src - (size_t)dest1);

	return(0);
}*/
