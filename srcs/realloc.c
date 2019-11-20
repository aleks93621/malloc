/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 10:36:26 by aaleksov          #+#    #+#             */
/*   Updated: 2019/11/20 10:52:34 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*c;
	unsigned char	*d;
	int				i;

	i = 0;
	if (n == 0 || dest == src)
		return (dest);
	d = (unsigned char *)src;
	c = (unsigned char*)dest;
	while (0 < n)
	{
		c[i] = d[i];
		n--;
		i++;
	}
	return (c);
}

size_t	min_size(size_t a, size_t b)
{
	return (a >= b ? b : a);
}

void	zone_and_blocsize(t_zone *zone, t_bloc *bloc, size_t size)
{
	zone->actual_size -= bloc->bloc_size + size;
	bloc->bloc_size = size;
}

void	*malloc_cpy(t_zone *zone, t_bloc *bloc, size_t size)
{
	void	*new_malloc;

	new_malloc = ft_malloc(size);
	if (new_malloc)
	{
		ft_memcpy(new_malloc, POINT_B(bloc), min_size(size, bloc->bloc_size));
		ft_free(POINT_B(bloc));
	}
	return (new_malloc);
}

void	*ft_realloc(void *ptr, size_t size)
{
	t_bloc	*bloc_ptr;
	t_zone	*zone;

	if (!ptr)
		return (ft_malloc(size));
	else if (size == 0)
		ft_free(ptr);
	else if ((bloc_ptr = searchbloc_with_addr(ptr)) != NULL)
	{
		zone = searchzone_with_bloc(bloc_ptr);
		if (zone)
		{
			if (zone->type != LARGE && zone->type ==
			typeofzone_with_blocsize(size) && ((bloc_ptr->bloc_size <= size) ||
			(size + zone->actual_size <= zone->zone_size)))
			{
				zone_and_blocsize(zone, bloc_ptr, size);
				return (ptr);
			}
			else
				return (malloc_cpy(zone, bloc_ptr, size));
		}
	}
	return (NULL);
}
