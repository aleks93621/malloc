/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 10:21:09 by aaleksov          #+#    #+#             */
/*   Updated: 2019/10/09 10:30:04 by aaleksov         ###   ########.fr       */
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

t_zone	*create_zone(size_t zone_size)
{
	t_zone *new_zone;

	new_zone = alloc_zone(zone_size);
	return (NULL);
}