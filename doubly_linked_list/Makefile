# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/13 15:36:02 by minseok2          #+#    #+#              #
#    Updated: 2023/02/10 15:19:29 by minseok2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libdll.a

CC = CC
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = -rcs
RM = rm
RMFLAGS = -rf

LIBFT_DIR = ../libft
LIBFT_NAME = ft

HEADER_DIR = includes

SRCS_DIR = srcs
SRCS = list_add.c \
	   list_delete.c \
	   list_peek.c \
	   list_basic.c

OBJS_DIR = objs
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

clean:
	make fclean -C $(LIBFT_DIR)
	$(RM) $(RMFLAGS) $(OBJS_DIR)

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)

re:
	make fclean
	make all

$(NAME): $(OBJS)
	make all -C $(LIBFT_DIR)
	$(AR) $(ARFLAGS) $@ $^

$(OBJS): $(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER_DIR)

.PHONY : all bonus clean fclean re
