/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:57:15 by aaleksov          #+#    #+#             */
/*   Updated: 2016/12/02 16:12:23 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int c;

	j = 0;
	i = 0;
	if (haystack[0] == '\0' && needle[0] == '\0')
		return ((char*)haystack);
	else if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		j = i;
		c = 0;
		while (haystack[j] == needle[c])
		{
			j++;
			c++;
			if (needle[c] == '\0')
				return ((char*)(&haystack[i]));
		}
		i++;
	}
	return (NULL);
}
