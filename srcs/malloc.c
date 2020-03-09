/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 12:07:22 by aaleksov          #+#    #+#             */
/*   Updated: 2020/03/09 13:53:48 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

pthread_mutex_t	g_mutex = PTHREAD_MUTEX_INITIALIZER;

static t_bloc	*split_bloc(t_bloc *bloc, size_t size)
{
	t_bloc		*new_bloc;
	t_bloc		*right;
	size_t		total_size;

	right = bloc->next;
	total_size = bloc->size + sizeof_bloc();
	new_bloc = (t_bloc *)((char *)bloc + sizeof_bloc() + size);
	new_bloc->size = total_size - size - sizeof_bloc() * 2;
	new_bloc->status = FREE;
	new_bloc->prev = bloc;
	new_bloc->next = bloc->next;
	bloc->size = size;
	bloc->next = new_bloc;
	if (right)
		right->prev = new_bloc;
	return (bloc);
}

static void		allocate_bloc(t_bloc *bloc, size_t size)
{
	if (g_zone.type != LARGE && bloc->size > size + sizeof_bloc())
		split_bloc(bloc, size);
	bloc->status = ALLOC;
}

void			*malloc(size_t size)
{
	t_bloc	*alloc_b;
	size_t	new_size;

	if ((int)size < 0)
		return (NULL);
	pthread_mutex_lock(&g_mutex);
	new_size = get_aligned_size(size, 16);
	zone_type_initialization(new_size);
	alloc_b = exist_or_expand(g_zone.current, new_size);
	if (!alloc_b)
		return (NULL);
	allocate_bloc(alloc_b, new_size);
	pthread_mutex_unlock(&g_mutex);
	return ((char *)alloc_b + sizeof_bloc());
}
