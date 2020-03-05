/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:33:06 by aaleksov          #+#    #+#             */
/*   Updated: 2020/03/05 13:03:50 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

static void	merge_free_blocs(t_bloc *b1, t_bloc *b2)
{
	t_bloc		*b2_next;

	if ((char *)b1 + sizeof_bloc() + b1->size == (char *)b2)
	{
		b1->size = b1->size + sizeof_bloc() + b2->size;
		b2_next = b2->next;
		b1->next = b2_next;
		if (b2_next)
			b2_next->prev = b1;
		b2->next = NULL;
		b2->prev = NULL;
		b2->size = 0;
	}
}

void		free_on(t_bloc *bloc)
{
	t_bloc	*left;
	t_bloc	*right;

	bloc->status = FREE;
	left = bloc->prev;
	right = bloc->next;
	if (g_zone.type == LARGE)
	{
		if (left)
			left->next = bloc->next;
		else
			g_zone.large = NULL;
		if (right)
			right->prev = bloc->prev;
		munmap(bloc, bloc->size + sizeof_bloc());
	}
	else
	{
		if (right && right->status == FREE)
			merge_free_blocs(bloc, right);
		if (left && left->status == FREE)
			merge_free_blocs(left, bloc);
	}
}

void		free(void *ptr)
{
	t_bloc	*b_to_free;

	if (ptr == NULL)
		return ;
	b_to_free = find_bloc(ptr);
	if (!b_to_free)
		return ;
	free_on(b_to_free);
}
