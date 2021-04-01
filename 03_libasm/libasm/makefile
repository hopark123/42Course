# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/30 13:24:29 by hopark            #+#    #+#              #
#    Updated: 2021/03/31 18:37:55 by hopark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

NA = nasm

NFLAGS = -f macho64

CC = gcc
CFLAGS = -Wall -Werror -Wextra -L. -lasm

SRC = ft_strlen.s		\
	ft_strcpy.s			\
	ft_strcmp.s			\
	ft_write.s			\
	ft_read.s			\
	ft_strdup.s			\


OBJ = $(SRC:.s=.o)

all: $(NAME)

$(NAME):
	$(NA) $(NFLAGS) ft_strlen.s
	$(NA) $(NFLAGS) ft_strcpy.s
	$(NA) $(NFLAGS) ft_strcmp.s
	$(NA) $(NFLAGS) ft_write.s
	$(NA) $(NFLAGS) ft_read.s
	$(NA) $(NFLAGS) ft_strdup.s
	ar rcs $(NAME) $(OBJ)
	ranlib $(NAME)
	
test : $(NAME)
	$(CC) $(CFLAGS) main.c -o $(NAME)


clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all