# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aevstegn <aevstegn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/07 23:21:25 by aevstegn          #+#    #+#              #
#    Updated: 2025/05/12 19:30:10 by aevstegn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = fractol
CC          = cc
CFLAGS      = -Wall -Wextra -Werror


MINILIBX    = -Lminilibx -lmlx -lX11 -lXext -lm
PRINTF_DIR  = ft_printf
PRINTF_LIB  = -L$(PRINTF_DIR)/libft -lft -L$(PRINTF_DIR) -lftprintf
PRINTF_LIB_FILE = $(PRINTF_DIR)/libftprintf.a

MANDATORY_SRCS = mandatory/main.c \
				 mandatory/events.c \
				 mandatory/draw.c \
				 mandatory/helpers.c \
				 mandatory/init.c \
				 mandatory/pixels.c
BONUS_SRCS     = bonus/main_bonus.c \
				 bonus/events_bonus.c \
				 bonus/draw_bonus.c

MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)
BONUS_OBJS     = $(BONUS_SRCS:.c=.o)


all: $(NAME)

$(NAME): $(MANDATORY_OBJS) $(PRINTF_LIB_FILE)
	$(CC) $(CFLAGS) $^ -o $@ $(MINILIBX) $(PRINTF_LIB)
	@echo "===== MANDATORY VERSION: $(NAME) ====="

bonus:  $(filter-out mandatory/main.o, $(MANDATORY_OBJS)) $(BONUS_OBJS) $(PRINTF_LIB_FILE)
	$(CC) $(CFLAGS) $^ -o $(NAME) $(MINILIBX) $(PRINTF_LIB) -DBONUS
	@echo "===== BONUS VERSION: $(NAME) ====="

$(PRINTF_LIB_FILE):
	@make -C $(PRINTF_DIR)

clean:
	@make -C $(PRINTF_DIR) clean
	@rm -f $(MANDATORY_OBJS) $(BONUS_OBJS)
	@echo "===== OBJS REMOVED ====="

fclean: clean
	@make -C $(PRINTF_DIR) fclean
	@rm -f $(NAME)
	@echo "===== OBJS AND BINARY REMOVED ====="

re: fclean all

.PHONY: all bonus clean fclean re