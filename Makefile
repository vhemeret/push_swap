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

SRCS =		list/*.c \
			parsing/*.c \
			sorting/*.c \
			utils/*.c \
			push_swap.c \

OBJS = ${SRCS:.c=.o}

NAME = push_swap
COMPIL = gcc -Wall -Wextra -Werror

all : ${NAME}

.c.o :
	${COMPIL} -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS)
			ar -rcs $(NAME) $(OBJS)

clean :		
			rm -f $(OBJS)

fclean : clean
			rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re