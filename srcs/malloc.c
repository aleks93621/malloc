/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 12:07:22 by aaleksov          #+#    #+#             */
/*   Updated: 2019/10/08 13:49:49 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/malloc.h"

t_zone  *alloc_zone(size_t zone_size)
{
    t_zone *new_zone;
    size_t alloc_size;

    alloc_size = zone_size;
    if (typeofzone_with_zonesize(zone_size) == LARGE)
        alloc_size += sizeof(t_zone) + sizeof(t_bloc);
    new_zone = mmap(0, alloc_size, PROT_READ | PROT_WRITE, \
                    MAP_ANON | MAP_PRIVATE, -1, 0);
    return (new_zone);
}

t_zone  *create_zone(size_t zone_size)
{
    t_zone *new_zone;

    new_zone = alloc_zone(zone_size);
    return (NULL);
}

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