# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/28 18:03:34 by hopark            #+#    #+#              #
#    Updated: 2021/05/05 18:13:14 by hopark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = checker
NAME2 = push_swap

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
	$(PUSH_SWAP) \
	$(CHECKER_DIR) \
	$(UTIL_DIR) \

SRC1 = \
	$(CHECKER) \
	$(ENGINE) \
	$(UTIL) \

SRC2 = \
	$(PUSH_SWAP) \
	$(ENGINE) \
	$(UTIL) \

OBJ1 = $(addprefix $(OBJ_DIR1)/, $(notdir $(SRC1:.c=.o)))
OBJ2 = $(addprefix $(OBJ_DIR2)/, $(notdir $(SRC2:.c=.o)))
OBJS = $(OBJ1) $(OBJ2) 
all : $(NAME1)

clean :
	$(RM) $(RMFLAGS) $(OBJS)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

test : all
	./checker 5 69 53 3 38 12 32 37 24 89 54 31 55 94 80 33 15 13 23 83 63 78 16 84 30 4 79 57 25 60 10 90 7 44 41 51 87 47 46 71 73 56 61 48 19 96 26 77 42 64 9 66 70 39 91 43 59 93 45 62 86 17 35 72 1 68 29 22 85 67 2 27 14 88 11 28 95 100 82 92 75 58 97 74 6 21 81 49 36 18 65 50 76 52 40 98 20 34 8 99

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