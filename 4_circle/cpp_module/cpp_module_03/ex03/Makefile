NAME = DiamondTrap
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
		ClapTrap.hpp \
		DiamondTrap.hpp \
		FragTrap.hpp \
		ScavTrap.hpp \
)

SRC = $(addprefix $(SRC_DIR)/, \
		ClapTrap.cpp \
		DiamondTrap.cpp \
		FragTrap.cpp \
		ScavTrap.cpp \
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
	./DiamondTrap

re : fclean all


OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.cpp=.o)))
$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)
$(OBJ_DIR)/%.o : %.cpp $(INC) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(NAME) : $(OBJ) $(INC)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -o $(NAME) $(OBJ)



.PHONY: all clean fclean re test\
