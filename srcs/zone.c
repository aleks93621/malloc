/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 08:49:31 by aaleksov          #+#    #+#             */
/*   Updated: 2019/11/15 09:59:21 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	init_zone(t_zone *new_zone, size_t bloc_size)
{
	new_zone->type = typeofzone_with_blocsize(bloc_size);
	new_zone->zone_size = sizeofzone_with_blocsize(bloc_size);
	new_zone->actual_size = 0;
	if (typeofzone_with_blocsize(bloc_size) == LARGE)
		new_zone->actual_size = SIZE_Z;
	new_zone->blocs = NULL;
	new_zone->next = NULL;
}

void	addzone_to_zones(t_zone *new_zone)
{
	t_zone *first_zone;

	first_zone = (t_zone*)g_first_addr;
	while (first_zone->next)
		first_zone = first_zone->next;
	first_zone->next = new_zone;
}

t_zone	*alloc_zone(size_t bloc_size)
{
	t_zone *new_zone;
	size_t alloc_size;

	new_zone = NULL;
	alloc_size = sizeofzone_with_blocsize(bloc_size);
	if (typeofzone_with_blocsize(bloc_size) != LARGE)
		alloc_size += SIZE_Z;
	new_zone = mmap(0, alloc_size, PROT_READ | PROT_WRITE, \
					MAP_ANON | MAP_PRIVATE, -1, 0);
	return (new_zone);
}

t_zone	*create_zone(size_t bloc_size)
{
	t_zone *zone;

	zone = NULL;
	zone = alloc_zone(bloc_size);
	init_zone(zone, bloc_size);
	if (!g_first_addr)
		g_first_addr = (void*)zone;
	else if (zone)
		addzone_to_zones(zone);
	return (zone);
}
