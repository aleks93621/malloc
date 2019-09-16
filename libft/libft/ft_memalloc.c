/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 11:20:32 by aaleksov          #+#    #+#             */
/*   Updated: 2016/12/02 14:50:33 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void			*alloc;

	alloc = malloc(size);
	if (alloc == NULL)
		return (NULL);
	ft_memset(alloc, 0, size);
	return (alloc);
}
