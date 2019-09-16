/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:03:11 by aaleksov          #+#    #+#             */
/*   Updated: 2017/01/19 13:20:13 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_strcmp(const char *str1, const char *str2)
{
	unsigned int		i;
	unsigned char		*stru;
	unsigned char		*strd;

	stru = (unsigned char*)str1;
	strd = (unsigned char*)str2;
	i = 0;
	while ((stru[i] != '\0') || (strd[i] != '\0'))
	{
		if (stru[i] != strd[i])
			return (stru[i] - strd[i]);
		i++;
	}
	return (0);
}
