/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:38:31 by aaleksov          #+#    #+#             */
/*   Updated: 2019/10/08 13:47:08 by aaleksov         ###   ########.fr       */
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

typedef enum		e_mtype
{
	TINY,
	SMALL,
	LARGE
}					t_mtype;

typedef struct		s_zone
{
	t_mtype			type;
	size_t			zone_size;
	struct s_bloc	*blocs;
	struct s_zone	*next;
}					t_zone;

typedef struct		s_bloc
{
	size_t			bloc_size;
	struct s_bloc	*next;
}					t_bloc;

void				free(void *ptr);
void				*malloc(size_t size);
void				*realloc(void *ptr, size_t size);

t_mtype				typeofzone_with_blocksize(size_t block_size);
size_t				sizeofzone_with_blocksize(size_t block_size);
t_mtype				typeofzone_with_zonesize(size_t zone_size);

#endif
