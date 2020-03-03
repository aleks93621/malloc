# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/17 11:45:43 by aaleksov          #+#    #+#              #
#    Updated: 2020/03/03 18:14:32 by aaleksov         ###   ########.fr        #
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
CMAG=\x1B[35m
CCYA=\x1B[36m

NAME = libft_malloc_$(HOSTTYPE).so
LIB = libft_malloc.so

SRCS_PATH = ./srcs/

SRCS_NAME = exist_or_expand.c \
		malloc.c \
		utils.c \
		zone_init.c \
		write_utils.c \
		find_bloc.c \
		free.c \
		realloc.c \

SRCS=$(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS_PATH = ./objects/

OBJS_NAME = $(SRCS_NAME:.c=.o)

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

LIBRARY= ./includes/malloc.h

CC=gcc

FLAGS=-Wall -Werror -Wall

all: crdir $(NAME)

$(NAME): $(OBJS)
	@$(CC) -shared $(FLAGS) -o $@ $^ -I $(LIBRARY)
	@ln -sf $@ $(LIB)
	@echo "$(CBOL)$(CV)[MALLOC]Librairie .so créée:$(CNOR) $(CBOL)\t\t$@$(CNOR)"
	@echo "$(CBOL)$(CV)[MALLOC]Création du lien symbolique:$(CNOR)\t$(CBOL)$(CMAG)$@ > $(LIB)$(CNOR)"

crdir:
ifeq ("$(wildcard $(OBJS_PATH))", "")
	@mkdir -p $(OBJS_PATH)
	@echo "$(CBOL)$(CV)[MALLOC]Création du dossier:$(CNOR)\t\t$(CBOL)$(OBJS_PATH)$(CNOR)"
else
	@echo "$(CBOL)$(CR)[MALLOC]Le dossier ./objects existe déjà$(CNOR)"
endif

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@$(CC) $(FLAGS) -fPIC -o $@ -c $<
	@echo "$(CBOL)$(CCYA)[MALLOC]Compilation des sources:$(CNOR)\t$(CBOL)./$<$(CNOR)"

clean:
	@rm -rf $(OBJS_PATH)
	@echo "$(CBOL)$(CR)[MALLOC]$(NOR)$(CBOL)Suppression des objets$(CNOR)";

fclean: clean
	@rm -rf $(NAME) $(LIB)
	@echo "$(CBOL)$(CR)[MALLOC]$(NOR)$(CBOL)Suppression des fichiers supplémentaires$(CNOR)";

re: fclean all

.PHONY: all clean fclean re crdir
