/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:38:31 by aaleksov          #+#    #+#             */
/*   Updated: 2019/11/22 10:44:13 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/mman.h>
# include <stdio.h>

# define MIN_ALLOC (size_t)100
# define TINY_SIZE (size_t)128
# define SMALL_SIZE (size_t)1024
# define TINY_ZONE (size_t)ZONE_CALC(TINY_SIZE)
# define SMALL_ZONE (size_t)ZONE_CALC(SMALL_SIZE)
# define ZONE_CALC(SIZE)(size_t)(SIZE*MIN_ALLOC/getpagesize()+1)*getpagesize()
# define SIZE_Z sizeof(t_zone)
# define SIZE_B sizeof(t_bloc)
# define POINT_Z(zone) (void*)(zone + 1)
# define POINT_B(bloc) (void*)(bloc + 1)
# define CNORM	"\x1B[0m"
# define CROU	"\x1B[31m"
# define CVER	"\x1B[32m"
# define CJAU	"\x1B[33m"
# define CBLE	"\x1B[34m"
# define CMAG	"\x1B[35m"
# define CCYA	"\x1B[36m"
# define CBLA	"\x1B[37m"
# define CBOL	"\x1b[1m"

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
	size_t			actual_size;
	struct s_bloc	*blocs;
	struct s_zone	*next;
}					t_zone;

typedef struct		s_bloc
{
	size_t			bloc_size;
	struct s_bloc	*next;
}					t_bloc;

void				*g_first_addr;

void				*malloc(size_t size);
void				free(void *ptr);
void				*realloc(void *ptr, size_t size);
void				show_alloc_mem();

size_t				sizeofzone_with_blocsize(size_t bloc_size);
t_mtype				typeofzone_with_blocsize(size_t bloc_size);
t_bloc				*searchbloc_with_addr(void *ptr);
t_zone				*searchzone_with_bloc(t_bloc *bloc);

t_zone				*create_zone(size_t bloc_size);
void				init_zone(t_zone *new_zone, size_t bloc_size);
void				addzone_to_zones(t_zone *new_zone);

void				*addr_zone(t_zone *zone, void *z_addr);
void				init_bloc(t_bloc *new_bloc, size_t bloc_size);
void				addbloc_to_zone(t_bloc *new_bloc, t_zone *zone);
t_bloc				*create_bloc(t_zone *zone, size_t bloc_size);

void				remove_zone(t_zone *zone_rem);
void				removebloc_from_zone(t_zone *zone, t_bloc *bloc_rem);
void				unmap_zone(t_zone *zone);
int					page_is_free(t_zone *zone);
void				clean_zones(t_mtype zonetype);

void				*malloc_cpy(t_bloc *bloc, size_t size);
void				zone_and_blocsize(t_zone *zone, t_bloc *bloc, size_t size);
size_t				min_size(size_t a, size_t b);

void				display_total(size_t total);
void				display_bloc_infos(void *start, void *end, size_t size);
void				display_zone_infos(t_zone *zone, void *zone_addr);
void				ft_display_addr(size_t num, char *base_str, int base);
int					ft_len_num(size_t num, int base);

void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *s);
void				*ft_memcpy(void *dest, const void *src, size_t n);

#endif
