/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:14:48 by aaleksov          #+#    #+#             */
/*   Updated: 2016/12/05 14:37:20 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int i;
	int j;

	i = ft_strlen(dest);
	j = -1;
	while (src[++j])
	{
		if (src[j] == '\n')
		{
			dest[i] = src[j];
			return (dest);
		}
		dest[i] = src[j];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
