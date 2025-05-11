/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gostroum <gostroum@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:29:27 by gostroum          #+#    #+#             */
/*   Updated: 2025/05/08 16:08:53 by gostroum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static t_list	*initialize_dummy(t_list *lst, void *(*f)(void *))
{
	if (!lst || !f)
		return (NULL);
	return (ft_lstnew(NULL));
}

static void	cleanup(t_list **lst, void **data, void (*del)(void *))
{
	if (del)
		del(*data);
	ft_lstclear(lst, del);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*dummy;
	t_list	*curr;
	t_list	*prev;
	void	*data;

	dummy = initialize_dummy(lst, f);
	if (!dummy)
		return (NULL);
	prev = dummy;
	while (lst)
	{
		data = f(lst->content);
		curr = ft_lstnew(data);
		if (!curr)
		{
			cleanup(&dummy, &data, del);
			return (NULL);
		}
		prev->next = curr;
		prev = curr;
		lst = lst->next;
	}
	curr = dummy->next;
	free(dummy);
	return (curr);
}
