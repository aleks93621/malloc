/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affiche_hash_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 15:38:17 by aaleksov          #+#    #+#             */
/*   Updated: 2017/02/15 14:03:09 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	affiche_hash(t_flags flag)
{
	if (flag.conv == 'x')
		ft_putstr("0x");
	else if (flag.conv == 'X')
		ft_putstr("0X");
}
