/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 11:26:06 by aaleksov          #+#    #+#             */
/*   Updated: 2019/11/20 13:21:59 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

int	main(void)
{
	ft_malloc(120);
	ft_malloc(120);
	ft_malloc(120);
	ft_malloc(1024);
	ft_malloc(1024);
	ft_malloc(1024 * 32);
	ft_malloc(1024 * 1024);
	ft_malloc(1024 * 1024 * 16);
	ft_malloc(1024 * 1024 * 128);
	ft_malloc(1024);
	show_alloc_mem();
	return (0);
}
