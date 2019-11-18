/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 07:52:30 by aaleksov          #+#    #+#             */
/*   Updated: 2019/11/18 11:17:36 by aaleksov         ###   ########.fr       */
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
                printf("%d) bloc->bloc_size: %zu -- bloc-adresse %zu\n", j+1, bloc->bloc_size, (size_t)POINT_B(bloc));
                j++;
                bloc = bloc->next;
            }
        }
        printf("Nombre de blocs: %s%d%s\n\n", CROU, j, CNORM);
        zone = zone->next;
        i++;
        // printf("\n");
    }
    printf("%s------------------\nNombre de zones: %d%s\n", CJAU, i, CNORM);
}



int main()
{
    char **str;
    char **str2;
    int i = 0;
    str = (char**)ft_malloc(sizeof(char*) * 1);
    str2 = (char**)ft_malloc(sizeof(char*) * 1);    

    str[0] = (char*)ft_malloc(sizeof(char) * 8 + 1);
    str2[0] = (char*)ft_malloc(sizeof(char) * 8 + 1);  
    while (i < 8) {
        str[0][i] = '0';
        i++;
    }
    str[0][i] = '\0';
    i = 0;
    while (i < 8) {
        str2[0][i] = '0';
        i++;
    }
    str2[0][i] = '\0';
    printf("mot: %s\n", str[0]);
    ft_free(str[0]);
    ft_free(str);
    printf("mot2: %s\n", str2[0]);
    ft_free(str2[0]);
    ft_free(str);
    test_zone();

    return (0);
}