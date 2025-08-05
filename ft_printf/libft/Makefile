# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aevstegn <aevstegn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 15:50:07 by aevstegn          #+#    #+#              #
#    Updated: 2025/03/14 15:37:10 by aevstegn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
FUNCTIONS = ${shell find -name \*.c}
OBJECTS = ${FUNCTIONS:.c=.o}

all: ${NAME}

${NAME}: ${OBJECTS}
	ar rcs ${NAME} ${OBJECTS}
	
%.o:%.c
	${CC} ${CFLAGS} -I libft -c $< -o $@

clean:
	rm -f ${OBJECTS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: clean fclean re