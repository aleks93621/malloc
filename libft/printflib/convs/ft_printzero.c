/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printzero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 12:28:37 by aaleksov          #+#    #+#             */
/*   Updated: 2017/01/27 14:05:10 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	write_zero_space(t_flags flag, int a)
{
	int	i;

	i = a;
	while (i < flag.width)
	{
		if (flag.zero != 0 && flag.minus == 0)
			ft_putchar('0');
		else
			ft_putchar(' ');
		i++;
	}
}
