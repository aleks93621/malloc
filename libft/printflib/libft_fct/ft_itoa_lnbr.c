/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_lnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 13:43:11 by aaleksov          #+#    #+#             */
/*   Updated: 2017/01/17 15:40:16 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_nf(long *n, int *negative)
{
	if (*n < 0)
	{
		*n *= -1;
		*negative = 1;
	}
}

static int		taille(long n)
{
	int len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char			*ft_itoa_lnbr(long n)
{
	int			neg;
	int			len;
	char		*str;
	long long	i;
	long long	j;

	j = -9223372036854775807;
	i = (long long)n;
	if (i == j - 1)
		return (ft_strdup("-9223372036854775808"));
	neg = 0;
	ft_nf(&n, &neg);
	len = taille(n) + neg;
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	while (len--)
	{
		str[len] = (n % 10) + '0';
		n = n / 10;
	}
	if (neg == 1)
		str[0] = '-';
	return (str);
}
