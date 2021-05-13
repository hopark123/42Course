# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/28 18:03:34 by hopark            #+#    #+#              #
#    Updated: 2021/05/13 14:15:46 by hopark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = checker
NAME2 = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
#CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
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
		ft_exit.c \
		ft_htsetting.c \
		ft_init.c \
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
		ft_memory2.c \
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

all : $(NAME1)

bonus : $(NAME2)

clean :
	$(RM) $(RMFLAGS) $(OBJS)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME1) $(NAME2)

re : fclean all bonus

test1 : $(NAME1)
	./push_swap -v "2 1 " "3 4 one"
test2 : $(NAME1)
	./push_swap -c "27 33 94 21 34 62 73 41 17 72 61 20 91 5 74 87 22 70 66 39 59 40 10 26 1 57 30 90 31 58 53 63 65 52 50 92 83 14 79 29 55 36 51 6 18 43 75 45 35 12 38 80 88 54 32 69 89 25 56 78 86 9 37 82 28 71 7 68 81 19 99 47 15 97 48 11 49 46 8 24 2 96 95 98 67 23 64 60 100 44 4 85 42 3 77 13 84 76 93 16"
test3 : $(NAME1) $(NAME2)
	./push_swap -88 -86 76 -27 -91 28 23 10 -92 -31 74 -52 -93 95 -69 34 -56 93 22 35 -82 14 -16 -12 18 0 -53 4 -45 -66 19 -51 33 30 63 -47 91 -3 -22 -89 -2 29 80 -19 -4 -90 -67 90 -41 83 -99 -9 -24 20 -8 -77 -80 -18 -55 46 64 68 -10 -64 13 -14 -23 -1 -21 -100 60 99 79 15 55 6 -15 -33 39 -94 11 -62 40 43 -84 75 44 78 73 24 -44 -73 87 -7 -39 -75 57 54 2 81  | ./checker -88 -86 76 -27 -91 28 23 10 -92 -31 74 -52 -93 95 -69 34 -56 93 22 35 -82 14 -16 -12 18 0 -53 4 -45 -66 19 -51 33 30 63 -47 91 -3 -22 -89 -2 29 80 -19 -4 -90 -67 90 -41 83 -99 -9 -24 20 -8 -77 -80 -18 -55 46 64 68 -10 -64 13 -14 -23 -1 -21 -100 60 99 79 15 55 6 -15 -33 39 -94 11 -62 40 43 -84 75 44 78 73 24 -44 -73 87 -7 -39 -75 57 54 2 81

$(OBJ_DIR1)/%.o : %.c | $(OBJ_DIR1)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@
	@mkdir -p $(OBJ_DIR1)

$(OBJ_DIR2)/%.o : %.c | $(OBJ_DIR2)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@
	@mkdir -p $(OBJ_DIR2)

$(NAME1) : $(INCLUDES) $(OBJ1)
		$(CC) $(CFLAGS) -o $(NAME1) $(OBJ1)

$(NAME2) : $(INCLUDES) $(OBJ2)
		$(CC) $(CFLAGS) -o $(NAME2) $(OBJ2)

.PHONY: all clean fclean re test\