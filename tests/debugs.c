/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxxx <xxxxxxxx@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 07:52:30 by xxxxxxxx          #+#    #+#             */
/*   Updated: 2020/03/05 12:11:50 by xxxxxxxx         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

int		test_align(void)
{
	void	*data;
	size_t	i;

	i = 1;
	while (i < 5000)
	{
		data = malloc(i);
		if ((uintptr_t)data % 16 != 0)
		{
			dprintf(STDERR_FILENO, "malloc(%zu) return non aligné", i);
			return (-1);
		}
		memset(data, 'a', i);
		free(data);
		i += 3;
	}
	return (0);
}

int		main(void)
{
	if (test_align() == -1)
		return (-1);
	return (0);
}
