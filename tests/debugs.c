/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 07:52:30 by aaleksov          #+#    #+#             */
/*   Updated: 2019/11/15 10:31:07 by aaleksov         ###   ########.fr       */
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
        printf("%s---- ZONE NUMERO %d ----%s\n", CVER, i + 1, CNORM);
        printf("zone-adresse: %zu\n", (size_t)POINT_Z(zone));
        printf("zone->size: %zu\n", zone->zone_size);
        printf("zone->actual_size: %zu\n", zone->actual_size);
        printf("Espace Libre: %zu\n", zone->zone_size - zone->actual_size);
        printf("zone->type: %s\n", zone->type == 0 ? "TINY" : zone->type == 1 ? "SMALL" : "LARGE");
        // printf("zone->type: %d\n", zone->type);
        printf("Sizeof(zone) = %zu / Sizeof(bloc) = %zu\n\n", SIZE_Z, SIZE_B);
        if (zone->blocs) {
            bloc = zone->blocs;
            j = 0;
            while (bloc)
            {
                // printf("%d) bloc->bloc_size: %zu -- bloc-adresse %zu\n", j+1, bloc->bloc_size, POINT_B(bloc));
                j++;
                bloc = bloc->next;
            }
            printf("Nombre de blocs: %s%d%s\n\n", CROU, j, CNORM);
        }
        zone = zone->next;
        i++;
        // printf("\n");
    }
    printf("%s------------------\nNombre de zones: %d%s\n", CJAU, i, CNORM);
}

int main()
{
    char **str;
    char *ptr;
    int i = 0;
    int nb_de_str = 10000;
    ptr = ft_malloc(8);
    // ft_malloc(90);
    // ft_malloc(4096);
    // ft_malloc(1000);
    // ft_malloc(1000);
    // ft_malloc(1000);
    str = (char**)ft_malloc(sizeof(char*) * nb_de_str);
    while (i < nb_de_str) {
        str[i] = (char*)ft_malloc(sizeof(char) * 2 + 1);
        str[i] = "ok";
        i++;
    }
    // printf("Valeur renvoyée par malloc: %zu\n", (size_t)ptr);
    ft_free(ptr);
    // test_zone();

    return (0);
}