#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*curr;

	if (!lst)
		return ;
	curr = *lst;
	while (curr)
	{
		temp = curr;
		curr = curr->next;
		del(temp->content);
		free(temp);
	}
	*lst = curr;
}
