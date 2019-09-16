/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 13:23:33 by aaleksov          #+#    #+#             */
/*   Updated: 2017/02/01 13:29:54 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_checker_o(t_flags flag, va_list ap)
{
	if (flag.conv == 'O')
		return (ft_itoaoctalll(va_arg(ap, uintmax_t)));
	else if (flag.size == 'H')
		return (ft_itoaoctalhh((unsigned char)va_arg(ap, unsigned int)));
	else if (flag.size == 'h')
		return (ft_itoaoctalh((unsigned short)va_arg(ap, unsigned int)));
	else if (flag.size == 'l')
		return (ft_itoaoctalll(va_arg(ap, unsigned long)));
	else if (flag.size == 'L')
		return (ft_itoaoctalll(va_arg(ap, unsigned long long)));
	else if (flag.size == 'j')
		return (ft_itoaoctalll(va_arg(ap, uintmax_t)));
	else if (flag.size == 'z')
		return (ft_itoaoctalll(va_arg(ap, size_t)));
	else if (flag.size == '.')
		return (ft_itoabase(va_arg(ap, unsigned int), 8));
	else
		return (NULL);
}
