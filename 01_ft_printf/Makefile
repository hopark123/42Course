# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hopark <hopark@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/23 13:16:57 by hopark            #+#    #+#              #
#    Updated: 2020/11/23 14:57:13 by hopark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

AR = ar
ARFLAGS = crs

CC = gcc
CFLAG = -Wall -Wextra -Werror

RM = rm
RMFLAG = -f

LIBFT = libft.a
LIBFT_DIR = libft/libft
LIBFT_FILE = $(LIBFT_DIR)/$(LIBFT)
LIBFT_INC_IDR = $(LIBFT_DIR)/include

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

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@
	
$(NAME) : $(INCLUDES) $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

.PHONY: all clean fclean re
