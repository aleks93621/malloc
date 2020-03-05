/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:57:33 by aaleksov          #+#    #+#             */
/*   Updated: 2020/03/05 12:01:33 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

static size_t	display_blocs(t_bloc *blocs)
{
	size_t	total;
	char	*start;
	char	*end;

	total = 0;
	while (blocs)
	{
		if (blocs->status == ALLOC)
		{
			start = (char*)blocs + sizeof_bloc();
			end = (char*)blocs + sizeof_bloc() + blocs->size;
			ft_putstr(CJAU);
			ft_print_addr((unsigned long long)start);
			ft_putstr(" - ");
			ft_print_addr((unsigned long long)end);
			ft_putstr(CNORM);
			ft_putstr(" : ");
			ft_putsizet((size_t)(end - start));
			ft_putendl(" octets");
			total += (size_t)(end - start);
		}
		blocs = blocs->next;
	}
	return (total);
}

void			ft_print_addr(unsigned long long int x)
{
	if (x / 16 == 0)
	{
		ft_putstr("0x");
		ft_putchar(BASE_HEXA[x % 16]);
	}
	else
	{
		ft_print_addr(x / 16);
		ft_putchar(BASE_HEXA[x % 16]);
	}
}

void			display_zone(t_bloc *blocs, size_t *total)
{
	if (blocs == NULL)
		ft_putendl("NULL");
	else
	{
		ft_print_addr((unsigned long long)blocs);
		ft_putstr("\n");
		*total += display_blocs(blocs);
	}
}

void			show_alloc_mem(void)
{
	size_t	total;

	total = 0;
	print_tiny();
	display_zone(g_zone.tiny, &total);
	print_small();
	display_zone(g_zone.small, &total);
	print_large();
	display_zone(g_zone.large, &total);
	print_total(total);
}
