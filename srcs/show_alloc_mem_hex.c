/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:10:59 by aaleksov          #+#    #+#             */
/*   Updated: 2020/03/05 14:32:55 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

static void	print_zones_hex(t_bloc *blocs)
{
	int i;

	i = 0;
	while (blocs)
	{
		if (blocs->status == ALLOC)
		{
			mem_dump_hex((char *)blocs + sizeof_bloc(), blocs->size);
			i++;
		}
		blocs = blocs->next;
	}
	if (i == 0)
	{
		ft_putstr(CROU);
		ft_putendl("There are no allocations in this type of zone");
		ft_putstr(CNORM);
	}
}

void		show_alloc_mem_hex(void)
{
    print_tiny_hex();
    print_zones_hex(g_zone.tiny);
}