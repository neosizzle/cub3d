/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jng <jng@student.42kl.edu>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:11:05 by jng               #+#    #+#             */
/*   Updated: 2022/01/24 14:11:20 by jng              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	c;
	size_t	res_len;
	char	*hay;

	i = 0;
	hay = (char *)big;
	res_len = ft_strlen(little);
	if (res_len == 0 || big == little)
		return (hay);
	while (hay[i] && i < len)
	{
		c = 0;
		while (hay[i + c] && little[c]
			&& hay[i + c] == little[c] && i + c < len)
			c++;
		if (c == res_len)
			return (hay + i);
		i++;
	}
	return (0);
}
