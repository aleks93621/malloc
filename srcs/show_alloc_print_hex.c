/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_print_hex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 11:32:18 by aaleksov          #+#    #+#             */
/*   Updated: 2020/03/09 13:07:02 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	print_tiny_hex(void)
{
	ft_putstr(CVER);
	ft_putstr(CBOL);
	ft_putendl("--- TINY -----------------");
	ft_putstr(CNORM);
}

void	print_small_hex(void)
{
	ft_putstr(CVER);
	ft_putstr(CBOL);
	ft_putendl("--- SMALL ----------------");
	ft_putstr(CNORM);
}

void	print_large_hex(void)
{
	ft_putstr(CVER);
	ft_putstr(CBOL);
	ft_putendl("--- LARGE ----------------");
	ft_putstr(CNORM);
}
