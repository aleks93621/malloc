/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_wstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 15:18:23 by aaleksov          #+#    #+#             */
/*   Updated: 2017/02/10 17:42:56 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		checker_wchar(wchar_t wstr)
{
	if (wstr > 0xFF && MB_CUR_MAX == 1)
		return (-1);
	else if (wstr > 0x7FF && MB_CUR_MAX == 2)
		return (-1);
	else if (wstr > 0xFFFF && MB_CUR_MAX == 3)
		return (-1);
	else if (wstr > 0x10FFFF && MB_CUR_MAX == 4)
		return (-1);
	return (0);
}
