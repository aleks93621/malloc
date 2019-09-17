/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 09:26:09 by aaleksov          #+#    #+#             */
/*   Updated: 2016/12/02 14:51:33 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int	i;
	char			*ok;
	char			*dst;

	dst = (char*)dest;
	ok = (char*)src;
	i = 0;
	while (i < n)
	{
		dst[i] = ok[i];
		if (ok[i] == c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
