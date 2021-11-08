# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/13 01:17:04 by kyuhkim           #+#    #+#              #
#    Updated: 2021/10/20 13:45:50 by kyuhkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= clang++
FLAG			= -Wall -Wextra -Werror
NAME			= ft_container
TEST			= test
SRC				=	\
					ft_container.cpp
OBJ				= ${SRC:.cpp=.o}

%.o : %.cpp
	$(CC) $(FALG) -o $@ -c $?

$(NAME) : $(OBJ)
	ar src $@ $^

$(TEST) : $(NAME)
	$(CC) $(FALG) -o $(TEST) test.cpp $(NAME)


clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f test

re: fclean $(NAME)

all: re
