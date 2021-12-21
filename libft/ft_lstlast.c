#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*curr;

	if (!lst)
		return (0);
	curr = lst;
	while (curr->next)
		curr = curr->next;
	return (curr);
}
