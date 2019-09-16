/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printvoid_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 10:41:37 by aaleksov          #+#    #+#             */
/*   Updated: 2017/02/09 14:49:36 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printvoid_hex(t_flags flag, va_list ap)
{
	int e;

	flag.size = 'l';
	flag.hash = 1;
	flag.conv = 'x';
	flag.plus = 2;
	e = ft_printhex(flag, ap);
	return (e);
}
