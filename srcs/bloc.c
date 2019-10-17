/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bloc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 10:52:49 by aaleksov          #+#    #+#             */
/*   Updated: 2019/10/17 12:33:00 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_bloc	*addr_zone(void *zone)
{
	t_bloc	*new_bloc;

	new_bloc = (t_bloc*)zone;
	return (new_bloc);
}

void	init_bloc(t_bloc *new_bloc, size_t bloc_size)
{
	if (new_bloc)
	{
		new_bloc->bloc_size = bloc_size;
		new_bloc->next = NULL;
	}
}

void	addbloc_to_zone(t_bloc *new_bloc, t_zone *zone)
{
	t_bloc *zone_blocs;

	zone_blocs = zone->blocs;
	if (!zone_blocs)
		zone->blocs = new_bloc;
	else
	{
		while (zone_blocs->next)
			zone_blocs = zone_blocs->next;
		zone_blocs->next = new_bloc;
	}
	zone->actual_size += new_bloc->bloc_size + SIZE_B;
}

t_bloc	*create_bloc(t_zone *zone, size_t bloc_size)
{
	t_bloc *new_bloc;

	new_bloc = NULL;
	new_bloc = addr_zone(POINT_Z(zone));
	init_bloc(new_bloc, bloc_size);
	addbloc_to_zone(new_bloc, zone);
	return (new_bloc);
}
