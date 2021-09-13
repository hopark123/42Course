NAME = Animal
CC = clang++
CFLAGS = -std=c++03 -Wall -Wextra -Werror
RM = rm
RMFLAGS = -f

OBJ_DIR = obj

INC_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = obj

vpath %.cpp $(SRC_DIR)

INC = $(addprefix $(INC_DIR)/, \
		Animal.hpp \
		Cat.hpp \
		Dog.hpp \
		WrongAnimal.hpp \
		WrongCat.hpp \
)

SRC = $(addprefix $(SRC_DIR)/, \
		Animal.cpp \
		Cat.cpp \
		Dog.cpp \
		WrongAnimal.cpp \
		WrongCat.cpp \
		main.cpp \
)

OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.cpp=.o)))

all : $(NAME)

clean :
	$(RM) $(RMFLAGS) $(OBJ)

fclean :
	$(RM) $(RMFLAGS) $(NAME) $(OBJ) 
	rm -rf $(OBJ_DIR)

test :$(NAME)
	./Animal

re : fclean all


OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.cpp=.o)))
$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)
$(OBJ_DIR)/%.o : %.cpp $(INC) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(NAME) : $(OBJ) $(INC)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -o $(NAME) $(OBJ)



.PHONY: all clean fclean re test\
