/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 10:52:27 by aaleksov          #+#    #+#             */
/*   Updated: 2019/11/20 10:56:45 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

#define M (1024 * 1024)

void	print(char *s)
{
	write(1, s, strlen(s));
}

int		main(void)
{
	char	*addr1;
	char	*addr3;

	addr1 = (char*)ft_malloc(16 * M);
	strcpy(addr1, "Bonjours\n");
	print(addr1);
	addr3 = (char*)ft_realloc(addr1, 128 * M);
	addr3[127 * M] = 42;
	print(addr3);
	return (0);
}