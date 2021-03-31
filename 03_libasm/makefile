# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/30 13:24:29 by hopark            #+#    #+#              #
#    Updated: 2021/03/31 15:54:34 by hopark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

NA = nasm

NFLAGS = -f macho64

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
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all