# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/04 12:55:20 by juandrie          #+#    #+#              #
#    Updated: 2024/03/04 13:09:49 by juandrie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Account

SRCS =	Account.cpp\
		tests.cpp\
		

FLAGS = clang++ -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME):
	$(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all

.PHONY: all clean re