/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 12:07:22 by aaleksov          #+#    #+#             */
/*   Updated: 2019/10/15 09:27:55 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/malloc.h"

void    init_zone(t_zone *new_zone, size_t block_size)
{
    new_zone->type = typeofzone_with_blocsize(block_size);
    new_zone->zone_size = sizeofzone_with_blocsize(block_size);
    new_zone->actual_size = 0;
    new_zone->blocs = NULL;
    new_zone->next = NULL;
}

void    *ft_malloc(size_t size)
{
    t_bloc *new_bloc;
    t_zone *new_zone;
    size_t alloc_size;
    static int test = 0;

    new_bloc = NULL;
    new_zone = NULL;
    test += 1;
    alloc_size = sizeof(t_zone);
    alloc_size += sizeofzone_with_blocsize(size);
    if (get_first_zone())
        printf("%s - %d\n", "C est fait !", test);
    new_zone = mmap(0, alloc_size, PROT_READ | PROT_WRITE, \
					MAP_ANON | MAP_PRIVATE, -1, 0);
    init_zone(new_zone, size);
    printf("alloc_size: %zu - %d\n", alloc_size, test);
    printf("Zone->type: %d - %d\n", new_zone->type, test);
    if (!get_first_zone()) {
        printf("%s - %d\n\n", "Pas de first !", test);
        *first_zone() = new_zone;
    }
    return ((void*)new_bloc);
}

int main() {
    char *str;
    str = (char*)ft_malloc(30505);
    str = (char*)ft_malloc(1024);
    str = (char*)ft_malloc(100);
    // printf("%d\n", getpagesize());
    // t_memory *list = NULL;
    // list->a = 10;
    // list->next = NULL;
    // printf("%lu\n", TINY_ZONE);
    // printf("%lu\n", SMALL_ZONE);
    // printf("%d\n", getpagesize());
    // int i = 0;
    // while (i < 1024) {
    //     str = (char*)ft_malloc(1024);
    //     str[0] = 42;
    //     i++;
    // }

    return (0);
}