/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 13:00:28 by aaleksov          #+#    #+#             */
/*   Updated: 2016/12/02 14:57:31 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*d;
	int				i;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	d = (char*)malloc(sizeof(*s) * (ft_strlen(s) + 1));
	if (d == NULL)
		return (NULL);
	while (s[i])
	{
		d[i] = f(s[i]);
		i++;
	}
	d[i] = '\0';
	return (d);
}
