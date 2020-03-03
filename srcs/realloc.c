/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:08:15 by aaleksov          #+#    #+#             */
/*   Updated: 2020/03/03 18:14:08 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

static void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst2;
	unsigned char	*src2;

	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	if (src < dst)
	{
		src2 = src2 + len - 1;
		dst2 = dst2 + len - 1;
		while (len--)
			*dst2-- = *src2--;
	}
	else if (src >= dst)
	{
		while (len--)
			*dst2++ = *src2++;
	}
	return (dst);
}

static void	*reallocation(t_bloc *bloc, size_t size)
{
	char		*new;
	t_mtype     old_type;

	old_type = g_zone.type;
	new = (char *)malloc(size);
	ft_memmove(new, (char *)bloc + sizeof_bloc(), bloc->size);
	g_zone.type = old_type;
	free_on(bloc);
	return (new);
}

void		*ft_realloc(void *ptr, size_t size)
{
	size_t		new_size;
	t_bloc		*bloc;

	if ((int)size < 0)
		return (NULL);
	if (!ptr)
		return (malloc(size));
	bloc = find_bloc(ptr);
	if (!bloc)
		return (NULL);
	new_size = get_aligned_size(size, 16);
	if (bloc->size >= new_size)
		return (ptr);
	return (reallocation(bloc, new_size));
}
