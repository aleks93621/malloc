/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bloc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 10:52:17 by aaleksov          #+#    #+#             */
/*   Updated: 2019/10/11 13:19:18 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_bloc	*bloc_adress(void *address)
{
	t_bloc *bloc;

	bloc = (t_bloc*)address;
	return (bloc);
}

void	init_bloc(t_bloc *bloc, size_t bloc_size)
{
	if (bloc)
	{
		bloc->bloc_size = bloc_size;
		bloc->next = NULL;
	}
}

void	addbloc_to_zone(t_zone *zone, t_bloc *bloc)
{
	
}

t_bloc  *addbloc(t_zone *zone, void *address, size_t bloc_size)
{
	t_bloc *bloc;

	if (!zone)
		return (NULL);
	bloc = bloc_adress(address);
	init_bloc(bloc, bloc_size);
	addbloc_to_zone(zone, bloc);

	return (bloc);
}