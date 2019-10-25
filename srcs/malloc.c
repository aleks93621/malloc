/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 12:07:22 by aaleksov          #+#    #+#             */
/*   Updated: 2019/10/25 15:20:55 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/malloc.h"

void    test_zone()
{
    t_zone  *zone;
    t_bloc  *bloc;

    zone = (t_zone*)g_first_addr;
    bloc = NULL;
    int i = 0;
    while(zone)
    {
        // printf("Size zone: %zu\n", zone->zone_size);
        // printf("Size actuelle: %zu\n", zone->actual_size);
        // printf("Libre: %zu\n", zone->zone_size - zone->actual_size);
        // printf("Type zone: %d\n", zone->type);
        // if (zone->blocs) {
        //     bloc = zone->blocs;
        //     while (bloc)
        //     {
        //         // printf("Size bloc: %zu, Addr: %zu\n", bloc->bloc_size, (void*)bloc);
        //         bloc = bloc->next;
        //     }
        // }
        zone = zone->next;
        i++;
        // printf("\n");
    }
    printf("Nombre de pages: %d\n", i);
}

t_bloc  *search_for_zone(size_t bloc_size)
{
    t_zone  *zone;
    t_bloc  *bloc;

    bloc = NULL;
    zone = (t_zone*)g_first_addr;
    while(zone)
    {
        if (zone
        && zone->type == typeofzone_with_blocsize(bloc_size)
        && (bloc_size + SIZE_B + zone->actual_size) <= zone->zone_size) {
            return (bloc = create_bloc(zone, bloc_size));
        }
        zone = zone->next;
    }
    return (bloc);
}

void    *ft_malloc(size_t size)
{
    t_bloc  *new_bloc;
    t_zone  *new_zone;
    // static int tour = 0;

    // tour += 1;
    new_bloc = NULL;
    new_zone = NULL;
    if (size <= 0)
        return (NULL);
    new_bloc = search_for_zone(size);
    if (!new_bloc)
    {
        new_zone = create_zone(size);
        new_bloc = create_bloc(new_zone, size);
    }
    return (new_bloc + 1);
}

int main() {
    char *str;
    // str = ft_malloc(80);
    // printf("%p\n", str);
    // str = ft_malloc(100);
    // printf("%p\n\n", str);
    // str = ft_malloc(1000);
    // str = ft_malloc(847);
    // printf("%p\n\n", str);
    // printf("%lu\n", TINY_ZONE);
    // printf("%lu\n", SMALL_ZONE);
    // printf("%d\n", getpagesize());
    int i = 0;
    while (i < 1024) {
        str = (char*)ft_malloc(1024);
        str[0] = 42;
        i++;
    }
    test_zone();
    printf("%zu\n", ZONE_CALC(SMALL_SIZE));

    return (0);
}