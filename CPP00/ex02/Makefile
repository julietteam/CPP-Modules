# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/04 12:55:20 by juandrie          #+#    #+#              #
#    Updated: 2024/03/04 16:32:28 by juandrie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Account

SRCS =	Account.cpp\
		tests.cpp
		
FLAGS = c++ -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME):
	$(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re