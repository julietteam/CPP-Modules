# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/04 12:55:20 by juandrie          #+#    #+#              #
#    Updated: 2024/03/06 14:38:33 by juandrie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Account

SRCS =	Account.cpp\
		tests.cpp
		
FLAGS = c++ -Wall -Wextra -Werror -std=c++98 -MMD

OBJ = $(SRCS:.cpp=.o)

DEP = $(SRCS:.cpp=.d)

all: $(NAME)

$(NAME): $(OBJ)
	$(FLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp
	@$(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(DEP)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEP)