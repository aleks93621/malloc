/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:38:31 by aaleksov          #+#    #+#             */
/*   Updated: 2020/03/09 13:46:22 by aaleksov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/mman.h>
# include <stdio.h>
# include <pthread.h>

# define MIN_ALLOC 100
# define TINY_SIZE 352
# define SMALL_SIZE 4064
# define BASE_HEXA "0123456789ABCDEF"

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

typedef enum		e_status
{
	FREE,
	ALLOC
}					t_status;

typedef struct		s_bloc
{
	t_status		status;
	size_t			size;
	struct s_bloc	*prev;
	struct s_bloc	*next;
}					t_bloc;

typedef struct		s_zone
{
	t_mtype			type;
	t_bloc			*tiny;
	t_bloc			*small;
	t_bloc			*large;
	t_bloc			**current;
}					t_zone;

t_zone					g_zone;
extern pthread_mutex_t	g_mutex;

void				*calloc(size_t nmemb, size_t size);

void				*malloc(size_t size);
t_bloc				*exist_or_expand(t_bloc **blocs, size_t size);
void				zone_type_initialization(size_t size);

void				free(void *ptr);
void				free_on(t_bloc *bloc);

void				*realloc(void *ptr, size_t size);

t_bloc				*find_bloc(void *ptr);

void				show_alloc_mem(void);
void				print_tiny();
void				print_small();
void				print_large();
void				print_total(size_t total);

void				show_alloc_mem_hex(void);
void				print_tiny_hex();
void				print_small_hex();
void				print_large_hex();
void				mem_dump_hex(void *bloc_addr, size_t size);

void				ft_putstr(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putendl(char const *s);

size_t				get_aligned_size(size_t size, int align_size);
int					sizeof_bloc(void);
int					page_size(void);
void				ft_putsizet(size_t n);
void				ft_print_addr(unsigned long long int x);

#endif
