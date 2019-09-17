/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:44:31 by aaleksov          #+#    #+#             */
/*   Updated: 2016/12/02 14:51:19 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

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
