/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 06:02:26 by aaleksov          #+#    #+#             */
/*   Updated: 2020/03/09 13:19:14 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

void	print_tab(int *tab, int len)
{
	int	i;

	i = 0;
	ft_putstr(CVER);
	ft_putstr(CBOL);
	printf("Calloc int Tab[%d] = {", len);
	while (i < len)
	{
		printf("%d", tab[i]);
		if (i < len - 1)
			printf(", ");
		i++;
	}
	printf("}\n");
	ft_putstr(CNORM);
}

int		*fill_tab(int size_tab)
{
	int	i;
	int	*tab;

	tab = (int*)calloc(size_tab, sizeof(int));
	i = 0;
	while (i < size_tab)
	{
		tab[i] = i;
		i++;
	}
	return (tab);
}

int		main(void)
{
	int	*tab;
	int	tab_len;

	tab_len = 20;
	tab = fill_tab(tab_len);
	if (tab == NULL)
	{
		ft_putendl("Problème de mémoire");
		return (-1);
	}
	print_tab(tab, tab_len);
	ft_putchar('\n');
	show_alloc_mem();
	return (0);
}
