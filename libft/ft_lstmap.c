/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jng <jng@student.42kl.edu.my>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:10:10 by jng               #+#    #+#             */
/*   Updated: 2022/01/26 11:03:44 by jng              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*curr;

	if (!lst || !f)
		return (0);
	curr = ft_lstnew(f(lst->content));
	if (!curr)
		return (0);
	head = curr;
	lst = lst->next;
	while (lst)
	{
		curr->next = ft_lstnew(f(lst->content));
		if (!(curr->next))
		{
			ft_lstclear(&head, del);
			return (0);
		}
		curr = curr->next;
		lst = lst->next;
	}
	curr->next = 0;
	return (head);
}
