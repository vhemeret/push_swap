# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 19:41:34 by vahemere          #+#    #+#              #
#    Updated: 2021/12/04 23:15:54 by vahemere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =		ft_atoi.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_memcmp.c \
			ft_memmove.c \
			ft_strchr.c \
			ft_strlcpy.c \
			ft_strncmp.c \
			ft_strrchr.c \
			ft_toupper.c \
			ft_bzero.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_memchr.c \
			ft_memcpy.c \
			ft_memset.c \
			ft_strlcat.c \
			ft_strlen.c \
			ft_strnstr.c \
			ft_tolower.c \
			ft_substr.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_striteri.c \

OBJS = ${SRCS:.c=.o}

SRCSBONUS =	ft_lstnew.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstadd_front.c \
			ft_lstmap.c \

OBJSBONUS = ${SRCSBONUS:.c=.o}

NAME = libft.a
COMPIL = gcc -Wall -Wextra -Werror

all : ${NAME}

.c.o :
	${COMPIL} -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS)
			ar -rcs $(NAME) $(OBJS)

bonus : $(OBJS) $(OBJSBONUS)
			ar -rcs $(NAME) $(OBJS) $(OBJSBONUS)

clean :		
			rm -f $(OBJS) $(OBJSBONUS)

fclean : clean
			rm -f $(NAME)

re : fclean all

.PHONY : bonus all clean fclean re
