# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/23 13:16:57 by hopark            #+#    #+#              #
#    Updated: 2020/11/27 03:12:55 by hopark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

AR = ar
ARFLAGS = crs

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm
RMFLAG = -f

INC_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = ./obj

INCLUDES = $(addprefix $(INC_DIR)/, \
		libft.h \
)

SRC = $(addprefix $(SRC_DIR)/, \
	ft_bzero_c.c \
	ft_calloc_c.c \
	ft_int_len.c \
	ft_uint_len.c \
	ft_itoa.c \
	ft_uitoa.c \
	ft_max.c \
	ft_memcpy.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_strchr.c \
	ft_strlen.c \
)

vpath %.c \
	$(SRC_DIR)

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

all : $(NAME)

clean :
	@$(RM) $(RMFLAG) $(OBJS)

fclean : clean
	@$(RM) $(RMFLAG) $(NAME)

re : fclean all

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(NAME) : $(INCLUDES) $(OBJS)
	@$(AR) $(ARFLAGS) $@ $(OBJS)

.PHONY: all clean fclean re
