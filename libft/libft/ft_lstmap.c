/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:17:49 by aaleksov          #+#    #+#             */
/*   Updated: 2016/12/02 14:50:11 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *nlst;
	t_list *tmp;
	t_list *tmp2;

	if (!lst || !f)
		return (NULL);
	tmp2 = f(lst);
	nlst = ft_lstnew(tmp2->content, tmp2->content_size);
	if (nlst)
	{
		tmp = nlst;
		lst = lst->next;
		while (lst)
		{
			tmp2 = f(lst);
			tmp->next = ft_lstnew(tmp2->content, tmp2->content_size);
			if (!(tmp->next))
				return (NULL);
			tmp = tmp->next;
			lst = lst->next;
		}
	}
	return (nlst);
}
