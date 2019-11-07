/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:38:31 by aaleksov          #+#    #+#             */
/*   Updated: 2019/11/07 09:22:17 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include "../libft/libft/includes/libft.h"
# include <sys/mman.h>

# define MIN_ALLOC (size_t)100
# define TINY_SIZE (size_t)128
# define SMALL_SIZE (size_t)1024
# define TINY_ZONE (size_t)ZONE_CALC(TINY_SIZE)
# define SMALL_ZONE (size_t)ZONE_CALC(SMALL_SIZE)
# define ZONE_CALC(SIZE)(size_t)(SIZE*MIN_ALLOC/getpagesize()+1)*getpagesize()
# define SIZE_Z sizeof(t_zone)
# define SIZE_B sizeof(t_bloc)
# define POINT_Z(zone) (void*)(zone)
# define POINT_B(bloc) (void*)(bloc)

typedef enum		e_mtype
{
	TINY,
	SMALL,
	LARGE
}					t_mtype;

typedef struct		s_zone
{
	void			*addr;
	t_mtype			type;
	size_t			zone_size;
	size_t			actual_size;
	struct s_bloc	*blocs;
	struct s_zone	*next;
}					t_zone;

typedef struct		s_bloc
{
	void			*addr;
	size_t			bloc_size;
	struct s_bloc	*next;
}					t_bloc;

void				*g_first_addr;

void				*ft_malloc(size_t size);
void				ft_free(void *ptr);

size_t				sizeofzone_with_blocsize(size_t bloc_size);
t_mtype				typeofzone_with_blocsize(size_t bloc_size);

t_zone				*create_zone(size_t bloc_size);
void				init_zone(t_zone *new_zone, size_t bloc_size);
void				addzone_to_zones(t_zone *new_zone);

void				*addr_zone(t_zone *zone, void *z_addr);
void				init_bloc(t_bloc *new_bloc, size_t bloc_size);
void				addbloc_to_zone(t_bloc *new_bloc, t_zone *zone);
t_bloc				*create_bloc(t_zone *zone, size_t bloc_size);

#endif