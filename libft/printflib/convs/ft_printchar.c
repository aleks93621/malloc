/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 12:21:34 by aaleksov          #+#    #+#             */
/*   Updated: 2017/02/09 16:06:35 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printchar(t_flags flag, va_list ap)
{
	int	i;

	i = 1;
	if (flag.size == 'l' || flag.conv == 'C')
		return (ft_printwchar(flag, ap));
	if (flag.width != -1 && flag.minus == 0)
	{
		write_zero_space(flag, 1);
		ft_putchar(va_arg(ap, int));
		i = flag.width;
	}
	else if (flag.width != -1 && flag.minus != 0)
	{
		ft_putchar(va_arg(ap, int));
		write_zero_space(flag, 1);
		i = flag.width;
	}
	else
		ft_putchar(va_arg(ap, int));
	return (i);
}
