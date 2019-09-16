/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 11:54:16 by aaleksov          #+#    #+#             */
/*   Updated: 2017/01/17 15:49:50 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strnew(size_t size)
{
	char			*d;

	d = (char*)malloc(size + 1);
	if (d == NULL)
		return (NULL);
	ft_memset(d, (int)'\0', size + 1);
	return (d);
}
