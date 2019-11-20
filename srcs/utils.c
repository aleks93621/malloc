/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 11:22:06 by aaleksov          #+#    #+#             */
/*   Updated: 2019/11/20 12:42:41 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void			ft_putchar(char c)
{
	ft_putchar_fd(c, 1);
}

void			ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void			ft_putstr(char const *s)
{
	int i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
}
