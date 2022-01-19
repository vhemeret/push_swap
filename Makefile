# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/08 16:47:47 by vahemere          #+#    #+#              #
#    Updated: 2022/01/19 16:53:05 by vahemere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
OBJ_DIR =	objs
SRC_DIR	=	$(shell find srcs -type d)

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)
SRCS =	push_swap.c \
		data_list.c list_cleaning.c malloc_Dlist.c manage_list.c \
		error.c parsing.c \
		get_info.c manage_algo.c move.c sort_big.c sort_small.c sort_three.c sort_utils_big.c sort_utils.c \
		free.c ft_atoi.c ft_isdigit.c ft_putstr.c ft_split.c \

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))
NORM = norminette
CC = gcc
CFLAGS = -Wall -Wextra -Werror

COLOUR_GREEN=\033[0;32m
COLOUR_END=\033[0m

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "\n\t$(COLOUR_GREEN)***EXECUTABLE CREATED SUCCESSFULL***\n\n$(COLOUR_END)"

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR) :
	mkdir -p $@
	@echo "\n\t$(COLOUR_GREEN)OBJECT DIRECTORY CREATED\n\n$(COLOUR_END)"

clean:
	rm -rf $(OBJS) $(OBJ_DIR)
	@echo "\n\t$(COLOUR_GREEN)DELETE .O SUCCESSFULL\n\n$(COLOUR_END)"

fclean: clean
	rm -rf $(NAME)
	@echo "\n\t$(COLOUR_GREEN)DELETE EXECUTABLE SUCCESSFULL\n\n$(COLOUR_END)"

norm :
	@echo "$(COLOUR_GREEN)**CHECK NORM FILES**$(COLOUR_END)"
	@$(NORM) $< 

re: fclean all

.PHONY : all clean fclean norm re
