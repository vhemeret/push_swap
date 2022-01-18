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
NORM = norminette
NAME = push_swap
COMPIL = gcc -Wall -Wextra -Werror -g

COLOUR_GREEN=\033[0;32m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\t$(COLOUR_BLUE)***CREATION EXECUTABLE***$(COLOUR_END)"
	$(COMPIL) $(OBJS) -o $(NAME)
	@echo "\n\t$(COLOUR_GREEN)***EXECUTABLE CREATED SUCCESSFULL***\n\n$(COLOUR_END)"

$(OBJS): $(LIST) $(PARSING) $(SORTING) $(UTILS) $(MAIN)
	@echo "\t$(COLOUR_BLUE)**COMPILING FILES STARTED**$(COLOUR_END)"
	$(COMPIL) -c $(LIST) $(PARSING) $(SORTING) $(UTILS) $(MAIN)
	@echo "\n\t$(COLOUR_GREEN)***COMPILING SUCCESSFULL***\n\n$(COLOUR_END)"

clean:
	rm -rf $(OBJS)
	@echo "\n\t$(COLOUR_GREEN)***DELETE .O SUCCESSFULL***\n\n$(COLOUR_END)"

fclean: clean
	rm -rf $(NAME)
	@echo "\n\t$(COLOUR_GREEN)***DELETE EXECUTABLE SUCCESSFULL***\n\n$(COLOUR_END)"

norm :
	@echo "$(COLOUR_GREEN)**CHECK NORM FILES**$(COLOUR_END)"
	@$(NORM) $< 

re: fclean all

.PHONY : all clean fclean re