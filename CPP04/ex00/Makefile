# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julietteandrieux <julietteandrieux@stud    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/12 22:19:46 by julietteand       #+#    #+#              #
#    Updated: 2024/03/12 22:35:50 by julietteand      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Animal
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD
RM = rm -f

SRC = 	main.cpp\
		Animal.cpp\
		Dog.cpp\
		Cat.cpp\
		WrongAnimal.cpp\
		WrongCat.cpp

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