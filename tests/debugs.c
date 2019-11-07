/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 07:52:30 by aaleksov          #+#    #+#             */
/*   Updated: 2019/11/07 09:19:06 by aaleksov         ###   ########.fr       */
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
        // printf("Size zone: %zu\n", zone->zone_size);
        // printf("Size actuelle: %zu\n", zone->actual_size);
        printf("Addr Zone: %zu\n", zone->addr);
        printf("Libre: %zu\n", zone->zone_size - zone->actual_size);
        printf("Sizeof(zone) = %zu / Sizeof(bloc) = %zu\n", SIZE_Z, SIZE_B);
        printf("Type zone: %d\n\n", zone->type);
        if (zone->blocs) {
            bloc = zone->blocs;
            j = 0;
            while (bloc)
            {
                printf("Size bloc: %zu, Addr Bloc: %zu\n", bloc->bloc_size, (void*)bloc);
                j++;
                bloc = bloc->next;
            }
            // printf("Nombre de blocs %d sur la page %d\n", j, i+1);
        }
        zone = zone->next;
        i++;
        // printf("\n");
    }
    printf("\nNombre de pages: %d\n", i);
}

int main()
{
    char *str;
    char *str2;

    str = (char*)ft_malloc(sizeof(char) * 8);
    str2 = (char*)ft_malloc(sizeof(char) * 90);
    test_zone();

    return (0);
}