# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/08 16:47:47 by vahemere          #+#    #+#              #
#    Updated: 2022/01/08 16:47:47 by vahemere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAIN =		push_swap.c \

SRC =		*.c \

LIST=$(addprefix list/, $(SRC))
PARSING=$(addprefix parsing/, $(SRC))
SORTING=$(addprefix sorting/, $(SRC))
UTILS=$(addprefix utils/, $(SRC))

OBJS = ${SRC:.c=.o}

NAME = push_swap
COMPIL = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(COMPIL) $(OBJS) -o $(NAME)

$(OBJS): $(LIST) $(PARSING) $(SORTING) $(UTILS) $(MAIN)
	$(COMPIL) -c $(LIST) $(PARSING) $(SORTING) $(UTILS) $(MAIN)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re