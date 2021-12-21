#include <stdlib.h>
#include "libft.h"

//1. move the ptr to the right as long as the current char is found in set
//2. move the ending ptr to the left long as the pointed char is found in set
//3. return the substring 
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;

	if (!s1 || !set)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
	{
		s1++;
	}
	len = ft_strlen(s1);
	while (len && ft_strchr(set, s1[len]))
	{
		len--;
	}
	return (ft_substr(s1, 0, len + 1));
}
/*
int	main()
{

	return 0;
}*/
