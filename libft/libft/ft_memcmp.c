/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:16:19 by aaleksov          #+#    #+#             */
/*   Updated: 2016/12/02 14:51:13 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s_1;
	unsigned char	*s_2;
	int				i;

	i = 0;
	s_1 = (unsigned char*)s1;
	s_2 = (unsigned char*)s2;
	while (n > 0)
	{
		if (s_1[i] == s_2[i])
			i++;
		else
			return (s_1[i] - s_2[i]);
		n--;
	}
	return (0);
}
