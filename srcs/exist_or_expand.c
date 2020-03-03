/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exist_or_expand.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:52:44 by aaleksov          #+#    #+#             */
/*   Updated: 2020/03/03 17:18:49 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

static size_t	get_extend_size(size_t size)
{
	size_t	s;

	if (g_zone.type == TINY)
		s = (TINY_SIZE + sizeof_bloc()) * MIN_ALLOC;
	else if (g_zone.type == SMALL)
		s = (SMALL_SIZE + sizeof_bloc()) * MIN_ALLOC;
	else
		s = size + sizeof_bloc();
	return (get_aligned_size(s, page_size()));
}

static t_bloc	*extend_heap(size_t size, t_bloc *previous)
{
	t_bloc	*bloc;
	size_t	mmap_size;

	mmap_size = get_extend_size(size);
	bloc = mmap(0, mmap_size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE,
				-1, 0);
	if (bloc == MAP_FAILED)
		return (NULL);
	bloc->status = FREE;
	bloc->size = mmap_size - sizeof_bloc();
	bloc->next = NULL;
	bloc->prev = previous;
	if (previous)
		previous->next = bloc;
	return (bloc);
}

static t_bloc	*available_or_last_bloc(t_bloc *blocs, size_t size)
{
	while (blocs)
	{
		if (blocs->size >= size && blocs->status == FREE)
			return (blocs);
		if (!blocs->next)
			break ;
		blocs = blocs->next;
	}
	return (blocs);
}

static int		is_available_bloc(t_bloc *bloc, size_t size)
{
	return (bloc->size >= size && bloc->status == FREE ? 1 : 0);
}

t_bloc			*exist_or_expand(t_bloc **blocs, size_t size)
{
	t_bloc		*place;

	if (!*blocs)
	{
		*blocs = extend_heap(size, *blocs);
		return (*blocs);
	}
	place = available_or_last_bloc(*blocs, size);
	if (is_available_bloc(place, size) == 1)
		return (place);
	else
		return (extend_heap(size, place));
}
