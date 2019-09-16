/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 13:23:33 by aaleksov          #+#    #+#             */
/*   Updated: 2017/01/23 13:41:24 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_checker_uint(t_flags flag, va_list ap)
{
	if (flag.conv == 'U')
		return (ft_itoa_lluint(va_arg(ap, uintmax_t)));
	if (flag.size == 'H')
		return (ft_itoa_hhuint((unsigned char)va_arg(ap, unsigned int)));
	if (flag.size == 'h')
		return (ft_itoa_huint((unsigned short)va_arg(ap, unsigned int)));
	else if (flag.size == 'l')
		return (ft_itoa_luint(va_arg(ap, unsigned long)));
	else if (flag.size == 'L')
		return (ft_itoa_lluint(va_arg(ap, unsigned long long)));
	else if (flag.size == 'j')
		return (ft_itoa_lluint(va_arg(ap, uintmax_t)));
	else if (flag.size == 'z')
		return (ft_itoa_lluint(va_arg(ap, size_t)));
	else if (flag.size == '.')
		return (ft_itoaunsigned(va_arg(ap, unsigned int)));
	else
		return (NULL);
}
