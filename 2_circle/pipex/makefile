# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/22 14:12:16 by hjpark            #+#    #+#              #
#    Updated: 2021/07/13 19:40:40 by hjpark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc
# CFLAGS = -Wall -Wextra -Werror
# CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
# CFLAGS = -g3 -fsanitize=address
RM = rm
RMFLAGS = -f

SRC_DIR = src
INC_DIR = include

ENGINE_DIR = $(SRC_DIR)/engine
PARSING_DIR = $(SRC_DIR)/parsing
UTIL_DIR = $(SRC_DIR)/util
OBJ_DIR = obj

ENGINE = $(wildcard $(ENGINE_DIR)/*.c)
PASSING = $(wildcard $(PASSING_DIR)/*.c)
UTIL = $(wildcard $(UTIL_DIR)/*.c)

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
	$(PASSING) \
	$(UTIL) \
	$(wildcard $(SRC_DIR)/*.c)

OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

all : $(NAME)

clean :
	$(RM) $(RMFLAGS) $(OBJ)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

test2 : $(NAME)
	 ./pipex here_doc infile "ls -l" "grep a" "wc -l" outfile
test : $(NAME)
	 ./pipex infile "./checker 2 1 3" "cat -e" "grep a" "wc -l" outfile

$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(NAME) : $(INCLUDES) $(OBJ)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -o $(NAME) $(OBJ)

.PHONY: all clean fclean re test\
