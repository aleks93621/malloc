/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:41:32 by aaleksov          #+#    #+#             */
/*   Updated: 2016/12/02 16:08:03 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		longu;
	char	*ok;

	ok = (char*)s;
	longu = ft_strlen(ok);
	while (longu > 0)
	{
		if (s[longu] == (char)c)
			return ((char*)s + longu);
		longu--;
	}
	if (s[longu] == (char)c)
		return ((char*)s + longu);
	else
		return (NULL);
}
