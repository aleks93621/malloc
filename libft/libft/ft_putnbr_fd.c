/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 12:41:28 by aaleksov          #+#    #+#             */
/*   Updated: 2016/12/02 14:53:34 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char *d;

	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	if ((d = ft_itoa(n)))
	{
		ft_putstr_fd(d, fd);
		ft_strdel(&d);
	}
}
