# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/28 18:03:34 by hopark            #+#    #+#              #
#    Updated: 2021/05/09 18:01:47 by hopark           ###   ########.fr        #
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

INCLUDES = $(addprefix $(INC_DIR)/, \
		checker.h \
		engine.h \
		push_swap.h \
		type.h \
		utils.h \
)
CHECKER = $(addprefix $(CHECKER_DIR)/, \
		ft_action.c \
		ft_checker.c \
)

ENGINE = $(addprefix $(ENGINE_DIR)/, \
		ft_htsetting.c \
		ft_is_sort.c \
		ft_make_list.c \
		ft_make_split.c \
)

PUSH_SWAP = $(addprefix $(PUSH_SWAP_DIR)/, \
		ft_action_ps.c \
		ft_cnt_chunk.c \
		ft_find_pivot.c \
		ft_push_swap.c \
		ft_show.c \
		ft_sort_a.c \
		ft_sort_b.c \
		ft_sort.c \
		ft_three_a.c \
		ft_three_b.c \
		ft_two.c \
)

UTIL = $(addprefix $(UTIL_DIR)/, \
		ft_atoi.c \
		ft_bubblesort.c \
		ft_free.c \
		ft_list.c \
		ft_list2.c \
		ft_malloc.c \
		ft_max.c \
		ft_memory.c \
		ft_memset.c \
		ft_numlen.c \
		ft_split.c \
		ft_strncmp.c \
		ft_write.c \
		get_next_line.c \
)
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

SRC2 = \
	$(PUSH_SWAP) \
	$(ENGINE) \
	$(UTIL) \

OBJ1 = $(addprefix $(OBJ_DIR1)/, $(notdir $(SRC1:.c=.o)))
OBJ2 = $(addprefix $(OBJ_DIR2)/, $(notdir $(SRC2:.c=.o)))
OBJS = $(OBJ1) $(OBJ2) 

all : $(NAME1) $(NAME2)

clean :
	$(RM) $(RMFLAGS) $(OBJS)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

test1 : $(NAME1)
	./checker 2 1 3 4
test2 : $(NAME2)
	./push_swap -c 12 7 17 9 6 16 18 15 2 11 4 13 8 10 20 14 1 5 19 3
test3 : $(NAME1) $(NAME2)
	./push_swap 12 7 17 9 6 16 18 15 2 11 4 13 8 10 20 14 1 5 19 3  | ./checker 12 7 17 9 6 16 18 15 2 11 4 13 8 10 20 14 1 5 19 3 

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