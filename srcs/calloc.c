/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 12:16:43 by aaleksov          #+#    #+#             */
/*   Updated: 2020/03/05 12:19:49 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

static void	ft_bzero(void *s, size_t n)
{
	unsigned char	*s2;

	s2 = (unsigned char *)s;
	while (n--)
	{
		*s2 = 0;
		s2++;
	}
}

void		*calloc(size_t nmemb, size_t size)
{
	void	*alloc;

	if ((int)nmemb < 0 || (int)size < 0)
		return (NULL);
	alloc = malloc(nmemb * size);
	if (alloc)
		ft_bzero(alloc, nmemb * size);
	return (alloc);
}
