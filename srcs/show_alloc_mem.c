/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 11:09:31 by aaleksov          #+#    #+#             */
/*   Updated: 2019/11/20 13:21:04 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	display_total(size_t total)
{
	ft_putstr("\x1b[1m");
	ft_putstr(CROU);
	ft_putstr("Total : ");
	ft_putstr(CNORM);
	ft_display_addr(total, "0123456789", 10);
	ft_putstr(" octets\n");
}

void	display_bloc_infos(void *start, void *end, size_t size)
{
	ft_display_addr((size_t)start, "0123456789ABCDEF", 16);
	ft_putstr(" - ");
	ft_display_addr((size_t)end, "0123456789ABCDEF", 16);
	ft_putstr(" : ");
	ft_display_addr(size, "0123456789", 10);
	ft_putstr(" octets\n");
}

void	display_zone_infos(t_zone *zone, void *zone_addr)
{
	ft_putstr("\x1b[1m");
	ft_putstr(CVER);
	if (zone->type == 0)
		ft_putstr("TINY : ");
	else if (zone->type == 1)
		ft_putstr("SMALL : ");
	if (zone->type == 2)
		ft_putstr("LARGE : ");
	ft_putstr(CNORM);
	ft_putstr(CJAU);
	ft_display_addr((size_t)zone_addr, "0123456789ABCDEF", 16);
	ft_putstr(CNORM);
	ft_putstr("\n");
}

void	show_alloc_mem(void)
{
	t_zone	*zone;
	t_bloc	*blocs;
	size_t	total;

	zone = (t_zone*)g_first_addr;
	total = 0;
	while (zone)
	{
		display_zone_infos(zone, (void*)zone);
		blocs = zone->blocs;
		while (blocs)
		{
			display_bloc_infos(POINT_B(blocs), POINT_B(blocs) +
			blocs->bloc_size, blocs->bloc_size);
			total += blocs->bloc_size;
			blocs = blocs->next;
		}
		zone = zone->next;
	}
	display_total(total);
}
