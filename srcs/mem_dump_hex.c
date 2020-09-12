/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_dump_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:31:36 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/03/09 13:12:44 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

static void	ft_char_to_hex(char c)
{
	ft_putchar(BASE_HEXA[c / 16]);
	ft_putchar(BASE_HEXA[c % 16]);
}

static void	ft_print_hex_part(unsigned char *hex_part, size_t size_rest)
{
	size_t	i;

	i = 0;
	while (i < 16)
	{
		ft_char_to_hex(hex_part[i]);
		if (i == 7)
			ft_putstr("  ");
		else if (i != 15)
			ft_putchar(' ');
		i++;
	}
}

static void	ft_print_char_part(unsigned char *hex_part, size_t size_rest)
{
	size_t	i;

	i = 0;
	while (i < 16)
	{
		if (hex_part[i] >= 32 && hex_part[i] <= 126)
			ft_putchar(hex_part[i]);
		else
			ft_putchar('.');
		i++;
	}
}

static void	mem_dump_print_line(void *line_addr, size_t size_rest)
{
	ft_putstr(CJAU);
	ft_putstr(CBOL);
	ft_print_addr((unsigned long long)line_addr);
	ft_putstr(CNORM);
	ft_putstr("  ");
	ft_print_hex_part((unsigned char*)line_addr, size_rest);
	ft_putstr("  ");
	ft_putstr(CJAU);
	ft_print_char_part((unsigned char*)line_addr, size_rest);
	ft_putstr(CNORM);
	ft_putchar('\n');
}

void		mem_dump_hex(void *bloc_addr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		mem_dump_print_line(bloc_addr + i, size - i);
		i += 16;
	}
}
