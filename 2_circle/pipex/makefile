# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/22 14:12:16 by hjpark            #+#    #+#              #
#    Updated: 2021/07/14 20:18:16 by hjpark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc
# CFLAGS = -Wall -Wextra -Werror
# CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
CFLAGS = -fsanitize=address
RM = rm
RMFLAGS = -f

SRC_DIR = src
INC_DIR = include

ENGINE_DIR = $(SRC_DIR)/engine
PARSING_DIR = $(SRC_DIR)/parsing
UTIL_DIR = $(SRC_DIR)/util
OBJ_DIR = obj

INCLUDE = $(addprefix $(INC_DIR)/, \
	head.h \
	parsing.h \
	type.h \
	util.h \
)

vpath %.c \
	$(SRC_DIR) \
	$(ENGINE_DIR) \
	$(PARSING_DIR)\
	$(UTIL_DIR) \

SRC = \
	$(ENGINE) \
	$(UTIL) \
	pipex.c \

ENGINE = $(addprefix $(ENGINE_DIR)/, \
	ft_execve.c \
	ft_find_user.c \
	ft_redirect.c \
	ft_run_pipex.c \
)

UTIL = $(addprefix $(UTIL_DIR)/, \
	ft_close.c \
	ft_debug.c \
	ft_free.c \
	ft_list.c \
	ft_malloc.c \
	ft_split.c \
	ft_string.c \
	ft_string2.c \
	ft_write.c \
	get_next_line.c \
)

OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

all : $(NAME)

clean :
	$(RM) $(RMFLAGS) $(OBJ)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME) test1 test2

re : fclean all

test : $(NAME)
	 ./pipex infile "./checker 2 1 3" "cat -e" "cat -e" "cat -e" test1
test2 : $(NAME)
	 ./pipex here_doc pp "cat -e" "grep a" "sort" test2

$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(NAME) : $(INCLUDES) $(OBJ)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -o $(NAME) $(OBJ)

.PHONY: all clean fclean re test\
