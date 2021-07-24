# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/22 14:12:16 by hjpark            #+#    #+#              #
#    Updated: 2021/07/23 17:58:36 by hjpark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
# CFLAGS = -Wall -Wextra -Werror
# CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
# CFLAGS = -fsanitize=address
RM = rm
RMFLAGS = -f

INC_DIR = ../include

ENGINE_DIR = engine
UTIL_DIR = ../util
OBJ_DIR = obj

INCLUDE = $(addprefix $(INC_DIR)/, \
	philo_one.h \
	util.h \
)

vpath %.c \
	$(ENGINE_DIR) \
	$(UTIL_DIR) \

SRC = \
	$(ENGINE) \
	$(UTIL) \
	$(wildcard *.c)

ENGINE = $(wildcard $(ENGINE_DIR)/*.c)

UTIL = $(wildcard $(UTIL_DIR)/*.c)

# UTIL = $(addprefix $(UTIL_DIR)/, \
# )

OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

all : $(NAME)

clean :
	$(RM) $(RMFLAGS) $(OBJ)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME) test1 test2

re : fclean all

bonus : re

test : $(NAME)
	 ./philo 3 800 200 10

$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(NAME) : $(INCLUDES) $(OBJ)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -o $(NAME) $(OBJ)

.PHONY: all clean fclean re test\
