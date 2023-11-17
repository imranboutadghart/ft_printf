/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboutadg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 00:05:19 by iboutadg          #+#    #+#             */
/*   Updated: 2023/11/15 00:11:21 by iboutadg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	inicializer(t_list **prev, t_list **head, t_list **tmp, t_list *lst)
{
	*prev = NULL;
	*head = NULL;
	*tmp = lst;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*prev;
	t_list	*tmp;
	t_list	*head;
	t_list	*new_node;

	if (!lst || !f || !del)
		return (NULL);
	inicializer(&prev, &head, &tmp, lst);
	while (tmp)
	{
		new_node = ft_lstnew(f(tmp->content));
		if (!new_node)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		if (!head)
			head = new_node;
		else
			prev->next = new_node;
		prev = new_node;
		tmp = tmp->next;
	}
	return (head);
}
