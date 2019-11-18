/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 10:09:59 by aaleksov          #+#    #+#             */
/*   Updated: 2019/11/18 10:13:12 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	removebloc_from_zone(t_zone *zone, t_bloc *bloc_rem)
{
	t_bloc	*blocs;
	t_bloc	*tmp;

	blocs = zone->blocs;
	if (POINT_B(blocs) == POINT_B(bloc_rem))
		zone->blocs = bloc_rem->next;
	else
	{
		while (POINT_B(blocs->next) != POINT_B(bloc_rem))
			blocs = blocs->next;
		blocs->next = bloc_rem->next;
	}
}

void	remove_zone(t_zone *zone_rem)
{
	t_zone	*zone;

	zone = (t_zone*)g_first_addr;
	if (zone)
	{
		if (POINT_Z(zone_rem) == POINT_Z(zone))
			g_first_addr = (void*)zone_rem->next;
		else
		{
			while (POINT_Z(zone->next) != POINT_Z(zone_rem))
				zone = zone->next;
			zone->next = zone_rem->next;
		}
	}
}
