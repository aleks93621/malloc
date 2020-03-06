/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 06:02:26 by aaleksov          #+#    #+#             */
/*   Updated: 2020/03/06 06:57:33 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	print_tab(int *tab, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		printf("%d ", tab[i]);
		i++;
	}
	ft_putchar('\n');
}

void	fill_tab(int **tab)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		*tab[i] = i;
		i++;
	}
}

int	main(void)
{
	int	*tab;

	tab = (int*)calloc(20, sizeof(char));
	if (tab == NULL)
	{
		ft_putendl("Problème de mémoire");
		return (-1);
	}
	fill_tab(&tab);
	print_tab(tab, 20);
	return (0);
}