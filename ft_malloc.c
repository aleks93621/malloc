/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:12:27 by aaleksov          #+#    #+#             */
/*   Updated: 2019/09/16 11:24:32 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include "./libft/libft/includes/libft.h"

int main(int ac, char **av) {
    int i = 0;
    int nb;
    char c;
    char *str;

    nb = atoi(av[2]);
    c = av[1][0];
    str = (char*)mmap(0, nb + 1, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    i = 0;
    while (i < nb)
    {
        str[i] = c;
        i++;
    }
    str[i] = '\0';
    ft_printf("%s\n", str);
    return (0);
}