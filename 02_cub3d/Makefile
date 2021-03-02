# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/10 14:50:20 by hopark            #+#    #+#              #
#    Updated: 2021/03/01 15:46:36 by hopark           ###   ########.fr        #
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