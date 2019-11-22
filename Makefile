# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/17 11:45:43 by aaleksov          #+#    #+#              #
#    Updated: 2019/11/22 10:35:09 by aaleksov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

CV=\033[32m
CJ=\033[033m
CR=\x1b[31m
CBOL=\x1b[1m
CNOR=\033[0m

NAME = libft_malloc.so
LIB = libft_malloc_$(HOSTTYPE).so

SRCS_PATH=./srcs

SRCS_NAME=bloc.c \
		display_addr.c \
		free.c \
		malloc.c \
		realloc.c \
		removes.c \
		research.c \
		show_alloc_mem.c \
		utils.c \
		zone.c

SRCS=$(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS_PATH = ./objects/

OBJS_NAME = $(SRCS_NAME:.c=.o)

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

CC=gcc

FLAGS=-Wall -Werror -Wall

all: $(NAME)

$(NAME): $(LIB)
	@ln -sf $^ $@
	@echo "$(CBOL)$(CV)[MALLOC]Création du lien symbolique:$(CNOR)\t$(CBOL)$@$(CNOR)"



clean:
	@rm -rf $(OBJS_PATH)
	@echo "$(CBOL)(CR)[MALLOC]$(NOR)$(CBOL)\tSuppression des objets$(CNOR)";

fclean: clean
	@rm -rf $(NAME) $(LIB)
	@echo "$(CBOL)(CR)[MALLOC]$(NOR)$(CBOL)\tSuppression des fichiers supplémentaires$(CNOR)";

re: fclean all

.PHONY: all clean fclean re