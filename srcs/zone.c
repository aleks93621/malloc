/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 10:21:09 by aaleksov          #+#    #+#             */
/*   Updated: 2019/10/11 09:52:37 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_zone	*alloc_zone(size_t zone_size)
{
	t_zone *new_zone;
	size_t alloc_size;

	alloc_size = zone_size;
	if (typeofzone_with_zonesize(zone_size) == LARGE)
		alloc_size += sizeof(t_zone) + sizeof(t_bloc);
	new_zone = mmap(0, alloc_size, PROT_READ | PROT_WRITE, \
					MAP_ANON | MAP_PRIVATE, -1, 0);
	return (new_zone);
}

void	init_zone(t_zone *new_zone, size_t zone_size)
{
	new_zone->type = typeofzone_with_zonesize(zone_size);
	new_zone->zone_size = zone_size;
	new_zone->blocs = NULL;
	new_zone->next = NULL;
}

void	add_zone(t_zone *new_zone)
{
	t_zone	*zone_ptr;

	zone_ptr = get_first_zone();
	if (!zone_ptr)
		*first_zone() = new_zone;
	else
	{
		while (zone_ptr)
			zone_ptr = zone_ptr->next;
		zone_ptr->next = new_zone;
	}
}

t_zone	*create_zone(size_t zone_size)
{
	t_zone *new_zone;

	new_zone = alloc_zone(zone_size);
	if (new_zone)
	{
		init_zone(new_zone, zone_size);
		add_zone(new_zone);
	}
	return (new_zone);
}