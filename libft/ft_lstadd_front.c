#include "libft.h"
// t_list	*ft_lstnew(void *content)
// {
// 	t_list	*new;

// 	new = (t_list *)malloc(sizeof(t_list));
// 	if (!new)
// 		return (0);
// 	new->content = content;
// 	return (new);
// }
//case 1: no head
//case 2: got head
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		temp = *lst;
		*lst = new;
		new->next = temp;
	}
}
