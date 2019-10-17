/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   firstzone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 09:20:06 by aaleksov          #+#    #+#             */
/*   Updated: 2019/10/17 12:36:54 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_zone	**first_zone(void)
{
	static t_zone *first = NULL;

	return (&first);
}

t_zone	*get_first_zone(void)
{
	return (*first_zone());
}
