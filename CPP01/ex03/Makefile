# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/06 11:05:10 by juandrie          #+#    #+#              #
#    Updated: 2024/03/06 14:49:17 by juandrie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Brainz3
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD
RM = rm -f

SRC = 	main.cpp\
		HumanA.cpp\
		HumanB.cpp\
		Weapon.cpp\

OBJ = $(SRC:.cpp=.o)

DEP = $(SRC:.cpp=.d)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(DEP)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEP)