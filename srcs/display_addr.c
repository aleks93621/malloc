/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_addr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 12:41:52 by aaleksov          #+#    #+#             */
/*   Updated: 2019/11/20 13:20:51 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

int			ft_len_num(size_t num, int base)
{
	int	len;

	len = 0;
	while (num / base > 0)
	{
		num /= base;
		len++;
	}
	return (len + 1);
}

void		ft_convert_to_base(size_t num, char *base_str, int base, int len)
{
	char str[len];

	str[len] = '\0';
	len--;
	while (len >= 0)
	{
		str[len] = base_str[num % base];
		num /= base;
		len--;
	}
	if (base == 16)
		ft_putstr("0x");
	ft_putstr(str);
}

void		ft_display_addr(size_t num, char *base_str, int base)
{
	int		len;
	char	*str;

	if (num == 0 || (base != 16 && base != 10) || base_str == NULL)
		return ;
	len = ft_len_num(num, base);
	ft_convert_to_base(num, base_str, base, len);
}
