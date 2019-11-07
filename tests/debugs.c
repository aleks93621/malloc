/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 07:52:30 by aaleksov          #+#    #+#             */
/*   Updated: 2019/11/07 10:07:52 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void    test_zone()
{
    t_zone  *zone;
    t_bloc  *bloc;

    zone = (t_zone*)g_first_addr;
    bloc = NULL;
    int i = 0;
    int j = 0;
    while(zone)
    {
        printf("---- ZONE NUMERO %d ----\n", i + 1);
        printf("zone->addr: %zu\n", zone->addr);
        printf("zone->size: %zu\n", zone->zone_size);
        printf("zone->actual_size: %zu\n", zone->actual_size);
        printf("Espace Libre: %zu\n", zone->zone_size - zone->actual_size);
        printf("zone->type: %s\n", zone->type == 0 ? "TINY" : zone->type == 1 ? "SMALL" : "LARGE");
        printf("Sizeof(zone) = %zu / Sizeof(bloc) = %zu\n\n", SIZE_Z, SIZE_B);
        if (zone->blocs) {
            bloc = zone->blocs;
            j = 0;
            while (bloc)
            {
                printf("%d) bloc->bloc_size: %zu -- bloc->addr: %zu\n", j+1, bloc->bloc_size, bloc->addr);
                j++;
                bloc = bloc->next;
            }
            printf("Nombre de blocs: %d\n\n", j);
        }
        zone = zone->next;
        i++;
        // printf("\n");
    }
    printf("------------------\nNombre de zones: %d\n", i);
}

int main()
{
    char *str;

    ft_malloc(8);
    ft_malloc(90);
    ft_malloc(4096);
    ft_malloc(1000);
    ft_malloc(1000);
    ft_malloc(1000);
    // printf("\n\n\n");
    test_zone();

    return (0);
}