/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   research.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 09:18:54 by aaleksov          #+#    #+#             */
/*   Updated: 2019/10/15 09:25:25 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/malloc.h"

t_mtype typeofzone_with_blocsize(size_t bloc_size)
{
	printf("Test valeur zone_size: %zu - %zu\n", bloc_size, SMALL_ZONE);
    if (bloc_size <= TINY_SIZE)
        return (TINY);
    else if (bloc_size <= SMALL_SIZE)
        return (SMALL);     
    else
        return (LARGE);
}

size_t  sizeofzone_with_blocsize(size_t block_size)
{
    if (block_size <= TINY_SIZE)
        return (TINY_ZONE);
    else if (block_size <= SMALL_SIZE)
        return (SMALL_ZONE);     
    else
        return (block_size);
}
