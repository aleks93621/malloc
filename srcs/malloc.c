/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 12:07:22 by aaleksov          #+#    #+#             */
/*   Updated: 2019/10/09 10:28:34 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/malloc.h"

t_bloc  *create_bloc(size_t bloc_size, t_zone *zone)
{
    t_bloc *new_bloc;
    size_t zone_size;

    if (zone == NULL)
    {
        zone_size = sizeofzone_with_blocksize(bloc_size);
        zone = create_zone(zone_size);
    }
    new_bloc = addbloc_to_zone(zone, bloc_size);
    return (new_bloc);
}

void    *ft_malloc(size_t size)
{
    t_bloc *new_bloc;

    // new_bloc = search_for_zone(size);
    if ((typeofzone_with_blocksize(size) == LARGE) || !new_bloc)
        new_bloc = create_bloc(size, NULL);
    // printf("%d\n", typeofzone_with_blocksize(size));
    return NULL;
}

int main() {
    // printf("%d\n", getpagesize());
    // t_memory *list = NULL;
    ft_malloc(500);
    // list->a = 10;
    // list->next = NULL;
    printf("%lu\n", TINY_ZONE);
    printf("%lu\n", SMALL_ZONE);
    printf("%d\n", getpagesize());

    return (0);
}