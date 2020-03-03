/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 07:52:30 by aaleksov          #+#    #+#             */
/*   Updated: 2020/03/03 17:29:24 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void    test_zone()
{
}

int     test_align() {
    	for (size_t i = 1; i < 5000; i += 3) {

		void	*data = ft_malloc(i);

		if ((uintptr_t)data % 16 != 0) {
			dprintf(STDERR_FILENO, "malloc(%zu) returned a non aligned boundary", i);
			return -1;
		}
		memset(data, 'a', i);

		// free(data);
	}
    return (0);
}

int main()
{
    if (test_align() == -1)
        return (-1);
    return (0);
}