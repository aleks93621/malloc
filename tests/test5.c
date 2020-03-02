/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 10:56:46 by aaleksov          #+#    #+#             */
/*   Updated: 2020/03/02 18:53:57 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	print(char *s)
{
	write(1, s, strlen(s));
}

int		main(void)
{
	char	*addr;

	addr = ft_malloc(16);
	ft_free(NULL);
	ft_free((void *)addr + 5);
	if (ft_realloc((void *)addr + 5, 10) == NULL)
		print("Bonjours\n");
}
