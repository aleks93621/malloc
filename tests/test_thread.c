/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:23:49 by aaleksov          #+#    #+#             */
/*   Updated: 2020/03/09 16:11:05 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

void	*thread_func(void *vargp)
{
	char	*str;
	int		i;

	i = 0;
	while (i < 100)
	{
		str = malloc(16);
		str = malloc(16);
		str = realloc(str, 16);
		free(str);
		i++;
	}
	return (NULL);
}

int		main(void)
{
	pthread_t	thread_id[42];
	int			i;

	i = 0;
	while (i < 42)
	{
		pthread_create(&thread_id[i], NULL, thread_func, NULL);
		i++;
	}
	i = 0;
	while (i < 42)
	{
		printf("%s%s%d%s\n", CVER, CBOL, i, CNORM);
		pthread_join(thread_id[i], NULL);
		i++;
	}
	return (0);
}
