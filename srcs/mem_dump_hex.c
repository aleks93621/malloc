/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_dump_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:31:36 by aaleksov          #+#    #+#             */
/*   Updated: 2020/03/05 14:47:14 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	mem_dump_print_line(void *line_addr, size_t size_rest)
{
	ft_print_addr((unsigned long long)line_addr);
	ft_putchar('\n');
}

void	mem_dump_hex(void *bloc_addr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		mem_dump_print_line(bloc_addr + i, size - i);
		i += 16;
	}
}
