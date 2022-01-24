/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jng <jng@student.42kl.edu>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:10:47 by jng               #+#    #+#             */
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
char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*res;

	len = ft_strlen(s);
	res = (char *) malloc(len + 1);
	if (!res)
		return (0);
	i = 0;
	while (i < len)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = 0;
	return (res);
}
