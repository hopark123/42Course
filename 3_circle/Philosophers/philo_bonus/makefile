# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/22 14:12:16 by hjpark            #+#    #+#              #
#    Updated: 2021/07/31 16:21:29 by hjpark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror
# CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
# CFLAGS = -fsanitize=address
RM = rm
RMFLAGS = -f

INC_DIR = include

ENGINE_DIR = engine
UTIL_DIR = util
OBJ_DIR = obj

INCLUDE = $(addprefix $(INC_DIR)/, \
	philo_bonus.h \
	util.h \
)

vpath %.c \
	$(ENGINE_DIR) \
	$(UTIL_DIR) \

SRC = \
	$(ENGINE) \
	$(UTIL) \

ENGINE = $(addprefix $(ENGINE_DIR)/, \
		ft_check_death.c \
		ft_fork.c \
		ft_free_philo_bonus.c \
		ft_game.c \
		ft_init.c \
		ft_printf.c \
		philo_bonus.c \
)

UTIL = $(addprefix $(UTIL_DIR)/, \
		ft_atoi.c \
		ft_free.c \
		ft_get_time.c \
		ft_malloc.c \
		ft_string.c \
		ft_usleep.c \
		ft_write.c \
)

OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

all : $(NAME)

clean :
	$(RM) $(RMFLAGS) $(OBJ)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

test : $(NAME)
	 ./philo_bonus 4 410 200 200 200

$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(NAME) : $(INCLUDES) $(OBJ)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -o $(NAME) $(OBJ)

.PHONY: all clean fclean re test\
