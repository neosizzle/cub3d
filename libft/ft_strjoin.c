/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jng <jng@student.42kl.edu>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:10:51 by jng               #+#    #+#             */
/*   Updated: 2022/01/24 14:11:20 by jng              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
// size_t ft_strlen(const char *s)
// {
// 	int	res;

// 	res = 0;
// 	while (s[res])
// 		res++;
// 	return (res);
// }
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	char	*res;

	len = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc(len + 1);
	if (!res)
		return (0);
	i = 0;
	while (*s1)
		res[i++] = (*s1++);
	while (*s2)
		res[i++] = (*s2++);
	res[i] = 0;
	return (res);
}
/*
int	main()
{

	return 0;
}*/
