# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aevstegn <aevstegn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 14:51:28 by aevstegn          #+#    #+#              #
#    Updated: 2024/12/05 15:41:07 by aevstegn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
ARCHIVE = ar rcs
SOURCE = $(shell find . -name "*.c")
OBJECTS = $(SOURCE:.c=.o)
DIR_LIBFT = ./libft
LIBFT = ./libft/libft.a
MAKE = make
REMOVE = rm -f

all: $(NAME)

$(NAME) : $(OBJECTS) $(LIBFT)
	$(ARCHIVE) $@ $^
	@echo "=========== PRINTFLIBFT CREATED ==========="

$(LIBFT) :
	$(MAKE) -C $(DIR_LIBFT)
	@echo "=========== LIBFT CREATED ==========="

%.o:%.c
	$(CC) $(CFLAGS) -I . -c $< -o $@

clean:
	$(MAKE) -C $(DIR_LIBFT) clean
	$(REMOVE) $(OBJECTS)

fclean: clean
	$(MAKE) -C $(DIR_LIBFT) fclean
	$(REMOVE) $(NAME)
	@echo "=========== ALL CLEAN ==========="

re: fclean all

.PHONY: clean fclean re