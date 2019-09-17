/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:26:07 by aaleksov          #+#    #+#             */
/*   Updated: 2016/12/02 14:54:01 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int		*ft_range(int min, int max)
{
	int i;
	int *tableau;

	i = 0;
	if (min >= max)
		return (0);
	else
	{
		tableau = (int*)malloc(sizeof(int*) * (max - min));
		while (min != max)
		{
			tableau[i] = min;
			i++;
			min++;
		}
	}
	return (tableau);
}
