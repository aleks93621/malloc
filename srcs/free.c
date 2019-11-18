/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 09:21:22 by aaleksov          #+#    #+#             */
/*   Updated: 2019/11/18 10:28:04 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

int			page_is_free(t_zone *zone)
{
	if (zone->blocs)
		return (0);
	return (1);
}

void		clean_zones(t_mtype zonetype)
{
	t_zone		*zones;
	int			first;

	first = 1;
	zones = (t_zone*)g_first_addr;
	while (zones)
	{
		if (zones->type == zonetype)
		{
			if (first)
				first = 0;
			else if (page_is_free(zones))
				unmap_zone(zones);
		}
		zones = zones->next;
	}
}

void		unmap_zone(t_zone *zone)
{
	size_t	unmap_size;

	remove_zone(zone);
	unmap_size = zone->zone_size;
	if (zone->type != LARGE)
		unmap_size += SIZE_Z;
	munmap((void*)zone, unmap_size);
}

void		ft_free(void *ptr)
{
	t_bloc	*bloc_ptr;
	t_zone	*zone;

	bloc_ptr = searchbloc_with_addr(ptr);
	if (bloc_ptr)
	{
		zone = searchzone_with_bloc(bloc_ptr);
		if (zone)
		{
			zone->actual_size -= bloc_ptr->bloc_size + SIZE_B;
			if (zone->type == LARGE)
				zone->actual_size -= SIZE_Z;
			removebloc_from_zone(zone, bloc_ptr);
			if (zone->type == LARGE)
				unmap_zone(zone);
			else
				clean_zones(zone->type);
		}
	}
}
