# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/23 13:16:57 by hopark            #+#    #+#              #
#    Updated: 2020/11/23 14:04:11 by hopark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

AR = ar
ARFLAGS = crs

CC = gcc
CFLAG = -Wall -Wextra -Werror

RM = rm
RMFLAG = -f

INC_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = ./obj

INCLUDES = $(addprefix $(INC_DIR)/, \
		ft_putchar_fd.h \
)

SRCS = $(addprefix $(SRC_DIR)/, \
	ft_putchar_fd.c \
)

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

all : $(NAME)

clean :
	$(RM) $(RMFLAG) $(OBJS)

fclean : clean
	$(RM) $(RMFLAG) $(NAME)

re : fclean all

.c.o : $(SRCS) $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) $(OBJS)

$(OBJ_DIR)/%.o : %.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@
$(NAME) : $(INCLUDES) $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

.PHONY: all clean fclean re
