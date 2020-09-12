/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_show_alloc_mem_hex.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 11:26:06 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/03/09 13:13:00 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"
#include <time.h>

static void	fill_str(char *str, int str_len)
{
	int	i;
	int	rand_number;
	int	rand_char;

	i = 0;
	while (i < str_len)
	{
		rand_number = rand() % 2;
		rand_char = rand() % 95 + 32;
		if (rand_number == 1)
			str[i] = rand_char;
		i++;
	}
}

int			main(void)
{
	char	*str_tiny;
	char	*str_small;
	char	*str_large;

	srand(time(NULL));
	str_tiny = (char*)malloc(20);
	fill_str(str_tiny, 32);
	str_small = (char*)malloc(400);
	fill_str(str_small, 400);
	str_large = (char*)malloc(5000);
	fill_str(str_large, 8160);
	show_alloc_mem_hex();
	return (0);
}
