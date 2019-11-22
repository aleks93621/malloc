# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaleksov <aaleksov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/17 11:45:43 by aaleksov          #+#    #+#              #
#    Updated: 2019/11/22 09:13:35 by aaleksov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

CV=\033[32m
CJ=\033[033m
CNOR=\033[0m
CR=\x1b[31m


NAME = libft_malloc_$(HOSTTYPE).so

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

OBJS_PATH = objects/

OBJS_NAME = $(SRCS_NAME:.c=.o)

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

CC=gcc

FLAGS=-Wall -Werror -Wall

all: crdir $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJ_COLLEEN) -o ./Colleen/Colleen
	@echo "$(CV)------------ Colleen ...$(CNOR)"

%.o: %.c
	@clang $(FLAG) -o $@ -c $<
	@echo "$(CV)[DR_QUINE] : Compilation $<$(CNOR)";

clean:
	@rm -rf $(OBJ_SULLY) $(OBJ_GRACE) $(OBJ_COLLEEN)
	@echo "$(CR)[DR_QUINE] : Suppression des objets$(CNOR)";

fclean: clean
	@rm -rf ./Sully/Sully ./Colleen/Colleen ./Grace/Grace ./Sully/Sully_* ./Grace/Grace_kid.c
	@echo "$(CR)[DR_QUINE] : Suppression des fichiers supplementaires$(CNOR)";

re: fclean all

.PHONY: all clean fclean re