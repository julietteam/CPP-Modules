# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/25 17:00:32 by juandrie          #+#    #+#              #
#    Updated: 2024/03/25 17:00:39 by juandrie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Iter
CC = c++
CFLAGS = -g -Wall -Wextra -Werror -std=c++98 -MMD
RM = rm -f

SRC = 	main.cpp\

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