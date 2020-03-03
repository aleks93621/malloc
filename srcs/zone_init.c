/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zone_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:37:56 by aaleksov          #+#    #+#             */
/*   Updated: 2020/03/03 17:18:26 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void		zone_type_initialization(size_t size)
{
	if (size <= TINY_SIZE)
	{
		g_zone.type = TINY;
		g_zone.current = &g_zone.tiny;
	}
	else if (size <= SMALL_SIZE)
	{
		g_zone.type = SMALL;
		g_zone.current = &g_zone.small;
	}
	else
	{
		g_zone.type = LARGE;
		g_zone.current = &g_zone.large;
	}
}
