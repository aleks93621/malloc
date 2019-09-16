/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hhuint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 13:13:50 by aaleksov          #+#    #+#             */
/*   Updated: 2017/01/17 16:09:47 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_itoa_huint(unsigned short n)
{
	char			*d;
	unsigned short	i;
	int				longu;

	if (n == 65535)
		return (ft_strdup("65535"));
	longu = 2;
	i = n;
	while (i /= 10)
		longu++;
	if (!(d = (char*)malloc(sizeof(char) * longu)))
		return (NULL);
	d[--longu] = '\0';
	while (longu--)
	{
		d[longu] = n % 10 + '0';
		n = n / 10;
	}
	return (d);
}
