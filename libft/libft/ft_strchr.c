/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:19:02 by aaleksov          #+#    #+#             */
/*   Updated: 2016/12/02 14:55:12 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	car;
	char			*ok;

	ok = (char*)s;
	car = (unsigned char)c;
	i = 0;
	while ((ok[i] != car) && (ok[i] != '\0'))
		i++;
	if (ok[i] == car)
		return (ok += i);
	else
		return (NULL);
}
