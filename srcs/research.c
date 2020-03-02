/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   research.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 09:18:54 by aaleksov          #+#    #+#             */
/*   Updated: 2020/03/02 16:12:05 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_mtype	typeofzone_with_blocsize(size_t bloc_size)
{
	if (bloc_size <= TINY_SIZE)
		return (TINY);
	else if (bloc_size <= SMALL_SIZE)
		return (SMALL);
	else
		return (LARGE);
}

size_t	sizeofzone_with_blocsize(size_t bloc_size)
{
	if (bloc_size <= TINY_SIZE)
		return (TINY_ZONE);
	else if (bloc_size <= SMALL_SIZE)
		return (SMALL_ZONE);
	else
		return (bloc_size + SIZE_B + SIZE_Z);
}

t_bloc	*searchbloc_with_addr(void *ptr)
{
	t_zone	*zone;
	t_bloc	*blocs;

	zone = (t_zone*)g_first_addr;
	while (zone)
	{
		blocs = zone->blocs;
		while (blocs)
		{
			if (POINT_B(blocs) == ptr)
				return (blocs);
			blocs = blocs->next;
		}
		zone = zone->next;
	}
	return (NULL);
}

t_zone	*searchzone_with_bloc(t_bloc *bloc)
{
	t_zone	*zone;
	t_bloc	*blocs;

	zone = (t_zone*)g_first_addr;
	while (zone)
	{
		blocs = zone->blocs;
		while (blocs)
		{
			if (POINT_B(bloc) == POINT_B(blocs))
				return (zone);
			blocs = blocs->next;
		}
		zone = zone->next;
	}
	return (NULL);
}
