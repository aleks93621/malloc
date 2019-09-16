/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoaunsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:20:26 by aaleksov          #+#    #+#             */
/*   Updated: 2017/01/17 15:39:33 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_itoaunsigned(unsigned int n)
{
	char			*d;
	unsigned int	i;
	int				longu;

	if (n == 4294967295)
		return (ft_strdup("4294967295"));
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
