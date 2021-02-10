# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/10 14:50:20 by hopark            #+#    #+#              #
#    Updated: 2021/02/10 16:26:40 by hopark           ###   ########.fr        #
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
# CFLAGS += -I $(MLX_DIR)

INC_DIR = ./include
ENGINE_DIR = ./engine
GNL_DIR = ./gnl
UTILS_DIR = ./utiles
OBJ_DIR = ./obj

INCLUDES = $(addprefix $(INC_DIR)/, \
		cub3d_type.h \
		cub3d.h \
		get_next_line.h\
		utils.h\
)

ENGINE = $(addprefix $(ENGINE_DIR)/, \
		ft_check_wall.c \
		ft_draw_map.c \
		ft_drawing.c \
		ft_init.c \
		ft_key.c \
		ft_loop.c \
		ft_player.c \
		ft_ray_casing.c \
		ft_ray_draw.c \
		ft_sprite_draw.c \
)

GNL = $(addprefix $(GNL_DIR)/, \
		get_next_line_utils.c \
		get_next_line.c \
)

UTILS = $(addprefix $(UTILS_DIR)/, \
		ft_i_matric_mulit.c \
		ft_max.c \
		ft_rotation.c \
		ft_split.c \
		ft_swap.c \
		ft_vector_len.c \
)

vpath %.c \
	$(ENGINE_DIR) \
	$(GNL_DIR) \
	$(UTILS_DIR)

SRCS = \
	$(ENGINE) \
	$(GNL) \
	$(UTILS) \
	main.c \
	cub3d.c

OBJS = $(addrprefix $(OBJ_DIR) /, $(notdir $(SRCS:.c=.o)))

all : $(NAME)
	# ./a.out

clean : 
	$(RM) $(RMFLAGS) $(OBJS)

fclaen : clean
		$(RM) $(RMFLAGS) $(NAME) $(MLX)

re : fclean all

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I (INC_DIR) -c $< -o $@
	
$(NAME) : $(MLX_FILE) $(INCLUDES) $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

$(MLX) : $(MLX_FILE)

$(MLX_FILE) :
	make -C $(MLX_DIR)
	cp $(MLX_FILE) $(NAME)

# gcc -L ../mlx -lmlx -framework OpenGL -framework AppKit load_img.c -o test_load.out
