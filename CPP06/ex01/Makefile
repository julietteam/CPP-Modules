# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julietteandrieux <julietteandrieux@stud    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/21 11:51:12 by juandrie          #+#    #+#              #
#    Updated: 2024/03/23 17:19:36 by julietteand      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Serialization
CC = c++
CFLAGS = -g -Wall -Wextra -Werror -std=c++98 -MMD
RM = rm -f

SRC = 	main.cpp\
		Serializer.cpp\

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