/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_zone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 09:45:46 by aaleksov          #+#    #+#             */
/*   Updated: 2019/10/11 09:47:32 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_zone	**first_zone()
{
	static t_zone	**first = NULL;

	return (&first);
}

t_zone	*get_first_zone()
{
	return (*first_zone());
}