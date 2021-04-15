# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/10 14:50:20 by hopark            #+#    #+#              #
#    Updated: 2021/04/13 16:55:36 by hopark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm
RMFLAGS = -f

MLX = libmlx.a
MLX_DIR = ./minilibx_opengl_20191021
MLX_FILE = $(MLX_DIR)/$(MLX)
MLX_FLAGS = -L $(MLX_DIR) -lmlx -framework OpenGl -framework Appkit


SRC_DIR = src
INC_DIR = include
ENGINE_DIR = $(SRC_DIR)/engine
GNL_DIR = $(SRC_DIR)/gnl
UTILS_DIR = $(SRC_DIR)/utils
PASSING_DIR = $(SRC_DIR)/passing
OBJ_DIR = obj

INCLUDES = $(wildcard $(INC_DIR)/*.h)
ENGINE = $(wildcard $(ENGINE_DIR)/*.c)
GNL = $(wildcard $(GNL_DIR)/*.c)
PASSING = $(wildcard $(PASSING_DIR)/*.c)
UTILS = $(wildcard $(UTILS_DIR)/*.c)

SRC_DIR_B = src_B
INC_DIR_B = include_B
ENGINE_DIR_B = $(SRC_DIR_B)/engine_B
GNL_DIR_B = $(SRC_DIR_B)/gnl_B
UTILS_DIR_B = $(SRC_DIR_B)/utils_B
PASSING_DIR_B = $(SRC_DIR_B)/passing_B

INCLUDES_B = $(wildcard $(INC_DIR_B)/*.h)
ENGINE_B = $(wildcard $(ENGINE_DIR_B)/*.c)
GNL_B = $(wildcard $(GNL_DIR_B)/*.c)
PASSING_B = $(wildcard $(PASSING_DIR_B)/*.c)
UTILS_B = $(wildcard $(UTILS_DIR_B)/*.c)

vpath %.c \
	$(SRC_DIR) \
	$(ENGINE_DIR) \
	$(GNL_DIR) \
	$(PASSING_DIR) \
	$(UTILS_DIR) \
	$(SRC_DIR_B) \
	$(ENGINE_DIR_B) \
	$(GNL_DIR_B) \
	$(PASSING_DIR_B) \
	$(UTILS_DIR_B) \
	

SRCS = \
	$(ENGINE) \
	$(GNL) \
	$(PASSING) \
	$(UTILS) \
	$(wildcard $(SRC_DIR)/*.c)

SRCS_B = \
	$(ENGINE_B) \
	$(GNL_B) \
	$(PASSING_B) \
	$(UTILS_B) \
	$(wildcard $(SRC_DIR_B)/*.c)

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))
OBJS_B = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS_B:.c=.o)))

all : $(NAME)

clean :
	$(RM) $(RMFLAGS) $(OBJS)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME) $(MLX)

re : fclean all

bonus :  $(MLX_FILE) $(INCLUDES_B) $(OBJS_B)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS_B) $(MLX_FLAGS)

test : all
	./cub3D ./map.cub
	
$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
	$(CC) -I $(INC_DIR) -c $< -o $@
$(NAME) : $(MLX_FILE) $(INCLUDES) $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)
$(MLX) : $(MLX_FILE)
$(MLX_FILE) :
	make -C $(MLX_DIR)
	cp $(MLX_FILE) $(NAME)

.PHONY: all clean fclean re test\


NAME1= checker
NAME2= push_swap
SRC_PATH= srcs
HDR_PATH= includes
OBJ_PATH= obj
LIB_PATH= libft

SRC_NAME1= 	checker.c\
			errors.c\
			to_use.c\
			simple_free.c\
			list.c\
			moves.c\
			orderby.c\
			gen_sort.c\
			ok_ko.c\
			print.c\
			list_op.c\

SRC_NAME2=  swap.c\
			moves.c\
			list.c\
			to_use.c\
			simple_free.c\
			print.c\
			gen_sort.c\
			algo.c\
			algo_use.c\
			ok_ko.c\
			list_op.c\
			algo_500.c\

HDR_NAME= push_swap.h

OBJ_NAME1= $(SRC_NAME1:.c=.o)
OBJ1= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME1))
SRC1= $(addprefix $(SRC_PATH)/,$(SRC_NAME1))

OBJ_NAME2= $(SRC_NAME2:.c=.o)
OBJ2= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME2))
SRC2= $(addprefix $(SRC_PATH)/,$(SRC_NAME2))

HDR= $(addprefix $(HDR_PATH)/,$(HDR_NAME))

LIB= libft.a
# FLAGS= -Wall -Wextra -Werror
LLIB_FLAG= -L$(LIB_PATH) libft/libft.a
H_FLAG= -I $(HDR_PATH)

COMP= gcc

all: lib  $(NAME1) $(NAME2)

$(NAME1) : $(LIB_PATH)/$(LIB) $(OBJ1)
	@rm -rf $(NAME1)
	@$(COMP) $(H_FLAG) $(LLIB_FLAG) $(OBJ1) -o $@
	@echo "	Compilation of $(NAME1):  \033[1;32mOK\033[m"

$(NAME2) : $(LIB_PATH)/$(LIB) $(OBJ2)
	@rm -rf $(NAME2)
	@$(COMP) $(H_FLAG) $(LLIB_FLAG) $(OBJ2) -o $@
	@echo "	Compilation of $(NAME2):  \033[1;32mOK\033[m"

$(OBJ_PATH)/%.o:  $(SRC_PATH)/%.c $(HDR)
	@mkdir -p $(OBJ_PATH) 
	@$(COMP) $(FLAGS) $(H_FLAG)  -o $@ -c $<
lib:
	@make -sC $(LIB_PATH)

clean:
	@rm -rf $(OBJ_PATH)
	@make clean -C $(LIB_PATH)
	@echo "\033[1;33m>> all .o files are deleted.\033[0m" 

fclean: clean
	@rm -rf $(NAME1)
	@make fclean -C $(LIB_PATH)
	@echo "\033[0;31m>> $(NAME1)all obbjects are deleted.\033[0m" 
	@rm -rf $(NAME2)
	@echo "\033[0;31m>> $(NAME2) all obbjects are deleted.\033[0m" 

re : fclean all