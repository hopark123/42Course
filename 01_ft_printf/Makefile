# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hopark <hopark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/23 13:16:57 by hopark            #+#    #+#              #
#    Updated: 2020/11/27 03:01:37 by hopark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

AR = ar
ARFLAGS = rcs

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm
RMFLAGS = -f

LIBFT = libft.a
LIBFT_DIR = ./libft
LIBFT_FILE = $(LIBFT_DIR)/$(LIBFT)
LIBFT_INC_DIR = $(LIBFT_DIR)/include

INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj

INCLUDES = $(addprefix $(INC_DIR)/, \
		ft_printf_parse.h \
		ft_printf_type.h \
		ft_printf.h \
)

SRC_PARSE_DIR = $(SRC_DIR)/parse
SRC_PARSE = $(addprefix $(SRC_PARSE_DIR)/, \
		ft_check_flag.c \
		ft_check_lh.c \
		ft_check_precision.c \
		ft_check_width.c \
		ft_init_infor.c \
		ft_parsing.c \
		ft_printf.c \
)

SRC_PRINTF_DIR = $(SRC_DIR)/printf
SRC_PRINTF = $(addprefix $(SRC_PRINTF_DIR)/, \
		ft_make_content.c \
		ft_print_char.c \
		ft_print_int.c \
		ft_print_int2.c \
		ft_print_uint.c \
		ft_print_uint2.c \
		ft_print_string.c \
)

vpath %.c \
	$(SRC_DIR) \
	$(SRC_PARSE_DIR)	\
	$(SRC_PRINTF_DIR)

SRCS = \
	$(SRC_PRINTF) \
	$(SRC_PARSE)



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

$(NAME) : $(LIBFT_FILE) $(INCLUDES) $(OBJS)
	$(AR) $(ARFLAGS) $@ $(OBJS)

#libft

$(LIBFT) : $(LIBFT_FILE)

$(LIBFT_FILE) :
	@make --no-print-directory -C $(LIBFT_DIR)
	@cp $(LIBFT_FILE) $(NAME)

$(LIBFT)_clean :
	@make --no-print-directory -C $(LIBFT_DIR) clean

$(LIBFT)_fclean :
	@make --no-print-directory -C $(LIBFT_DIR) fclean



#test

TEST_FILE = test.c

test : $(NAME) $(TEST_FILE)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIBFT_INC_DIR) $(TEST_FILE) -o $(TEST_FILE:.c=.out) -L. -lftprintf -L./libft -lft
	@./$(TEST_FILE:.c=.out)
	@rm $(TEST_FILE:.c=.out)
	@rm -rf $(TEST_FILE:.c=.out.dSYM)

.PHONY : \
	all clean fclean re \
	$(LIBFT) $(LIBFT)_clean $(LIBFT)_fclean \
