/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 09:21:22 by aaleksov          #+#    #+#             */
/*   Updated: 2019/11/15 10:58:41 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_bloc	*searchbloc_with_addr(void *ptr)
{
	t_zone	*zone;
	t_bloc	*blocs;

	zone = (t_zone*)g_first_addr;
	while (zone)
	{
		blocs = zone->blocs;
		while (blocs)
		{
			if (POINT_B(blocs) == ptr)
			{
				printf("yes c bon bg\n");
				return (blocs);
			}
			blocs = blocs->next;
		}
		zone = zone->next;
	}
	return (NULL);
}

t_zone	*searchzone_with_bloc(t_bloc *bloc)
{
}

void	ft_free(void *ptr)
{
	t_bloc	*bloc_ptr;
	t_zone	*zone;

	bloc_ptr = searchbloc_with_addr(ptr);
	if (bloc_ptr)
	{
		zone = searchzone_with_bloc(bloc_ptr);
	}
	printf("%zu\n", bloc_ptr->bloc_size);
}
