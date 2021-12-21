#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (c > 255)
		c -= 256;
	if (c > 127)
		return (0);
	while (*s && *s != c)
		s++;
	if (*s == c)
		return ((char *)s);
	return (0);
}
