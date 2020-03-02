/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 12:07:22 by aaleksov          #+#    #+#             */
/*   Updated: 2020/03/02 18:44:22 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_bloc	*search_for_zone(size_t bloc_size)
{
	t_zone *zone;
	t_bloc *bloc;

	bloc = NULL;
	zone = (t_zone*)g_first_addr;
	while (zone)
	{
		if (zone
		&& zone->type == typeofzone_with_blocsize(bloc_size)
		&& (bloc_size + zone->actual_size + SIZE_B) < zone->zone_size)
			return (bloc = create_bloc(zone, bloc_size));
		zone = zone->next;
	}
	return (bloc);
}

void	*ft_malloc(size_t size)
{
	t_bloc *new_bloc;
	t_zone *new_zone;

	new_bloc = NULL;
	new_zone = NULL;
	if (size <= 0)
		return (NULL);
	if (typeofzone_with_blocsize(size) != LARGE)
		new_bloc = search_for_zone(size);
	if (!new_bloc)
	{
		new_zone = create_zone(size);
		new_bloc = create_bloc(new_zone, size);
	}
	return (POINT_B(new_bloc));
}
