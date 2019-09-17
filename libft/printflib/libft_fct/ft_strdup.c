/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:33:25 by aaleksov          #+#    #+#             */
/*   Updated: 2018/09/12 11:46:51 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strdup(const char *src)
{
	char	*cpy;

	cpy = NULL;
	cpy = (char*)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (cpy != NULL)
		ft_strcpy(cpy, src);
	return (cpy);
}
