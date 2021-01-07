# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/23 13:16:57 by hopark            #+#    #+#              #
#    Updated: 2021/01/03 11:58:43 by hopark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT = libft.a
LIBFT_DIR = ./libft
LIBFT_FILE = $(LIBFT_DIR)/$(LIBFT)
LIBFT_INC_DIR = $(LIBFT_DIR)/include

MLX = libmlx.a
MLX_DIR = minilibx_opengl_20191021
MLX_FLAGS = -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
MLX_FILE = $(MLX_DIR)/$(MLX)

INC_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = ./obj

INCLUDES = $(addprefix $(INC_DIR)/, \

)

SRCS = $(SRC_DIR)

vpath %.c \
	$(SRC_DIR) \


OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

all : $(NAME)

clean : $(LIBFT)_clean
	@$(RM) $(RMFLAGS) $(OBJS)

fclean : $(LIBFT)_fclean clean
	@$(RM) $(RMFLAGS) $(NAME)

re : fclean all

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIBFT_INC_DIR) -c $< -o $@

$(NAME) : cub3d.c $(MLX_FILES) $(LIBFT_FILE) $(INCLUDES) $(OBJS)
	$(CC) $(CDEBUG) $(CFLAGS) -I $(INC_DIR) -I $(LIBFT_INC_DIR) cub3d.c -o $(NAME) $(LIBFT_FLAGS) $(MLX_FLAGS)


#libft

$(LIBFT) : $(LIBFT_FILE)

$(LIBFT_FILE) :
	@make --no-print-directory -C $(LIBFT_DIR)
	@cp $(LIBFT_FILE) $(NAME)

$(LIBFT)_clean :
	@make --no-print-directory -C $(LIBFT_DIR) clean

$(LIBFT)_fclean :
	@make --no-print-directory -C $(LIBFT_DIR) fclean


.PHONY : \
	all clean fclean re \
	$(LIBFT) $(LIBFT)_clean $(LIBFT)_fclean \
	$(MLX) $(MLX)_clean
