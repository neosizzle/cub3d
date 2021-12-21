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
