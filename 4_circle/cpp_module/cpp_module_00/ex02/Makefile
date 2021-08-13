NAME = Account
CC = clang++
CFLAGS = -Wall -Wextra -Werror
RM = rm
RMFLAGS = -f

OBJ_DIR = obj

vpath %.cpp $(SRC_DIR)

INC = Account.hpp

SRC = Account.cpp, \
		test.cpp

OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.cpp=.o)))
$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.cpp $(INC) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

$(NAME) :$(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

all : $(NAME)

clean :
	$(RM) $(RMFLAGS) $(OBJ)

fclean :
	$(RM) $(RMFLAGS) $(NAME) $(OBJ) 
	rm -rf $(OBJ_DIR)

test :$(NAME)
	./Account

re : fclean all

.PHONY: all clean fclean re test\
