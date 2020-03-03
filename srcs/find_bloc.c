/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_bloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:54:29 by aaleksov          #+#    #+#             */
/*   Updated: 2020/03/03 17:57:09 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

static t_bloc	*look_for_addr_on(t_bloc *blocs, void *ptr)
{
	while (blocs)
	{
		if ((unsigned char *)blocs + sizeof_bloc() == (unsigned char *)ptr)
			return (blocs);
		blocs = blocs->next;
	}
	return (NULL);
}

t_bloc			*find_bloc(void *ptr)
{
	t_bloc		*bloc;

	bloc = look_for_addr_on(g_zone.large, ptr);
	if (bloc == NULL)
	{
		bloc = look_for_addr_on(g_zone.small, ptr);
		if (bloc == NULL)
		{
			bloc = look_for_addr_on(g_zone.tiny, ptr);
			if (bloc == NULL)
				return (NULL);
			g_zone.type = TINY;
		}
		else
			g_zone.type = SMALL;
	}
	else
		g_zone.type = LARGE;
	return (bloc);
}
