/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 11:22:06 by aaleksov          #+#    #+#             */
/*   Updated: 2020/03/03 17:20:00 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

size_t	get_aligned_size(size_t size, int align_size)
{
	if (size == 0)
		return (align_size);
	return ((size - 1) / align_size * align_size + align_size);
}

int		sizeof_bloc(void)
{
	return (get_aligned_size(sizeof(t_bloc), 16));
}

int		page_size(void)
{
	return (getpagesize());
}
