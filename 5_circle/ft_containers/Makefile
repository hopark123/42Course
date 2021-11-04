NAME = container
CC = clang++
CFLAGS = -std=c++03 -Wall -Wextra -Werror
RM = rm
RMFLAGS = -f

OBJ_DIR = obj

INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj

vpath %.cpp $(SRC_DIR)

INC = $(wildcard $(INC_DIR)/*.hpp)
SRC = $(wildcard $(SRC_DIR)/*.cpp)

OBJ = $(wildcard $(OBJ_DIR)/*.cpp, $(notdir $(SRC:.cpp=.o)))

all : $(NAME)

clean :
	$(RM) $(RMFLAGS) $(OBJ)

fclean :
	$(RM) $(RMFLAGS) $(NAME) $(OBJ) 
	rm -rf $(OBJ_DIR)

test :$(NAME)
	./container

re : fclean all


OBJ = $(wildcard $(OBJ_DIR)/, $(notdir $(SRC:.cpp=.o)))
$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)
$(OBJ_DIR)/%.o : %.cpp $(INC) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(NAME) : $(OBJ) $(INC)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -o $(NAME) $(OBJ)



.PHONY: all clean fclean re test\
