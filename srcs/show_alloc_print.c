/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 11:32:18 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/03/05 12:02:43 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	print_tiny(void)
{
	ft_putstr(CVER);
	ft_putstr(CBOL);
	ft_putstr("TINY : ");
	ft_putstr(CNORM);
}

void	print_small(void)
{
	ft_putstr(CVER);
	ft_putstr(CBOL);
	ft_putstr("SMALL : ");
	ft_putstr(CNORM);
}

void	print_large(void)
{
	ft_putstr(CVER);
	ft_putstr(CBOL);
	ft_putstr("LARGE : ");
	ft_putstr(CNORM);
}

void	print_total(size_t total)
{
	ft_putstr(CROU);
	ft_putstr(CBOL);
	ft_putstr("Total : ");
	ft_putstr(CNORM);
	ft_putsizet(total);
	ft_putendl(" octets");
}
