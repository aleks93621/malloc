/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 15:49:12 by aaleksov          #+#    #+#             */
/*   Updated: 2017/01/17 15:21:46 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_nf(int *n, int *negative)
{
	if (*n < 0)
	{
		*n *= -1;
		*negative = 1;
	}
}

char		*ft_itoa(int n)
{
	char	*d;
	int		i;
	int		negative;
	int		longu;

	longu = 2;
	negative = 0;
	i = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	ft_nf(&n, &negative);
	while (i /= 10)
		longu++;
	longu = longu + negative;
	if (!(d = (char*)malloc(sizeof(char) * longu)))
		return (NULL);
	d[--longu] = '\0';
	while (longu--)
	{
		d[longu] = n % 10 + '0';
		n = n / 10;
	}
	if (negative)
		d[0] = '-';
	return (d);
}
