# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 17:15:58 by juandrie          #+#    #+#              #
#    Updated: 2024/03/04 16:32:21 by juandrie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PhoneBook

SRCS =	main.cpp\
		Contact.cpp\
		PhoneBook.cpp\
		

FLAGS = c++ -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME):
	$(FLAGS) $(SRCS) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re