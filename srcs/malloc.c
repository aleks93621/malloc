/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 12:07:22 by aaleksov          #+#    #+#             */
/*   Updated: 2019/09/17 12:48:40 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/malloc.h"

void *malloc(size_t size)
{
    char *str;
    str = (char*)mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    return str;
}

int main() {
    int i = 0;
    char *str;

    // str = (char*)mmap(0, nb + 1, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);

    // str = (char*)malloc(sizeof(char) * 42);
    while (i < 1024) {
        str = (char*)malloc(1024);
        str[0] = 42;
        i++;
    }
    printf("%d\n", getpagesize());
    // str[i] = '\0';
    // ft_printf("%s\n", str);

    return (0);
}