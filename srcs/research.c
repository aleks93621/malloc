/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   research.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:53:58 by aaleksov          #+#    #+#             */
/*   Updated: 2019/10/08 13:46:20 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_mtype	typeofzone_with_blocksize(size_t block_size)
{
	if (block_size <= TINY_SIZE)
		return (TINY);
	else if (block_size <= SMALL_SIZE)
		return (SMALL);
	return (LARGE);
}

size_t	sizeofzone_with_blocksize(size_t block_size)
{
	if (block_size <= TINY_SIZE)
		return (TINY_ZONE);
	else if (block_size <= SMALL_SIZE)
		return (SMALL_ZONE);
	return (block_size);
}

t_mtype	typeofzone_with_zonesize(size_t zone_size)
{
	if (zone_size <= TINY_ZONE)
		return (TINY);
	else if (zone_size <= SMALL_ZONE)
		return (SMALL);
	return (LARGE);
}
