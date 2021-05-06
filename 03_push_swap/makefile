# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/28 18:03:34 by hopark            #+#    #+#              #
#    Updated: 2021/05/06 15:17:26 by hopark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = checker
NAME2 = push_swap2

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm
RMFLAGS = -f

SRC_DIR = src
INC_DIR = include
UTIL_DIR = $(SRC_DIR)/util
ENGINE_DIR = $(SRC_DIR)/engine
PUSH_SWAP_DIR = $(SRC_DIR)/push_swap
CHECKER_DIR = $(SRC_DIR)/checker
OBJ_DIR1 = obj1
OBJ_DIR2 = obj2

INCLUDES = $(wildcard $(INC_DIR)/*.h)
CHECKER = $(wildcard $(CHECKER_DIR)/*.c)
ENGINE = $(wildcard $(ENGINE_DIR)/*.c)
PUSH_SWAP = $(wildcard $(PUSH_SWAP_DIR)/*.c)
UTIL = $(wildcard $(UTIL_DIR)/*.c)

vpath %.c \
	$(SRC_DIR) \
	$(ENGINE_DIR) \
	$(PUSH_SWAP_DIR) \
	$(CHECKER_DIR) \
	$(UTIL_DIR) \

SRC1 = \
	$(CHECKER) \
	$(ENGINE) \
	$(UTIL) \
	$(PUSH_SWAP) \

SRC2 = \
	$(PUSH_SWAP) \
	$(ENGINE) \
	$(UTIL) \

OBJ1 = $(addprefix $(OBJ_DIR1)/, $(notdir $(SRC1:.c=.o)))
OBJ2 = $(addprefix $(OBJ_DIR2)/, $(notdir $(SRC2:.c=.o)))
OBJS = $(OBJ1) $(OBJ2) 

all : $(NAME1)

clean :
	$(RM) $(RMFLAGS) $(OBJ1)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

test : all
	./checker 52 28 21 32 84 4 15 39 45 24 20 99 33 66 57 26 25 79 31 88 58 42 64 5 2 54 36 68 62 55 37 11 40 75 22 89 46 81 10 74 61 51 72 35 49 38 69 29 1 44 30 95 34 19 60 82 70 65 63 87 93 100 56 98 48 92 12 90 53 3 59 47 76 13 8 67 78 96 91 16 14 86 97 43 77 6 7 18 94 50 71 27 83 41 73 85 9 80 23 17

$(OBJ_DIR1)/%.o : %.c | $(OBJ_DIR1)
	$(CC) -I $(INC_DIR) -c $< -o $@
	@mkdir -p $(OBJ_DIR1)

$(OBJ_DIR2)/%.o : %.c | $(OBJ_DIR2)
	$(CC) -I $(INC_DIR) -c $< -o $@
	@mkdir -p $(OBJ_DIR2)

$(NAME1) : $(INCLUDES) $(OBJ1)
		$(CC) $(CFLAGS) -o $(NAME1) $(OBJ1)

$(NAME2) : $(INCLUDES) $(OBJ2)
		$(CC) $(CFLAGS) -o $(NAME2) $(OBJ2)
.PHONY: all clean fclean re test\