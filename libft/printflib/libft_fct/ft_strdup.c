/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:33:25 by aaleksov          #+#    #+#             */
/*   Updated: 2017/01/17 15:37:35 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strdup(const char *s)
{
	char	*src2;
	int		taille;
	int		i;

	i = 0;
	taille = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	src2 = (char*)malloc((taille + 1) * sizeof(*s));
	if (src2 == NULL)
		return (NULL);
	else if (src2 != NULL)
	{
		while (i <= taille)
		{
			src2[i] = s[i];
			i++;
		}
	}
	src2[i] = '\0';
	return (src2);
}
