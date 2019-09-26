/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 12:07:22 by aaleksov          #+#    #+#             */
/*   Updated: 2019/09/26 14:59:07 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/malloc.h"

void *ft_malloc(size_t size)
{
    // char *str;
    // str = (char*)mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    
    // return str;
    t_memory *list = NULL;

    list->a = size;
    list->next = NULL;
    return NULL;
}

int main() {
    // int i = 0;
    // char *str;
    // while (i < 1024) {
    //     str = (char*)malloc(1024);
    //     str[0] = 42;
    //     i++;
    // }
    // printf("%d\n", getpagesize());
    t_memory *list = NULL;
    ft_malloc(10);
    list->a = 10;
    list->next = NULL;
    printf("%zu\n", list->a);

    return (0);
}