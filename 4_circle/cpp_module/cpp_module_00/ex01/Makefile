NAME = phonebook
CC = clang++
CFLAGS = -std=c++03 -Wall -Wextra -Werror
RM = rm
RMFLAGS = -f

INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj

vpath %.cpp $(SRC_DIR)

INC = $(addprefix $(INC_DIR)/, \
		phonebook.hpp \
)

SRC = $(addprefix $(SRC_DIR)/, \
		phonebook.cpp \
)

OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.cpp=.o)))

all : $(NAME)

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.cpp $(INC) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@


$(NAME) : $(OBJ) $(INC)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)


clean :
	$(RM) $(RMFLAGS) $(OBJ)

fclean :
	$(RM) $(RMFLAGS) $(NAME) $(OBJ) 
	rm -rf $(OBJ_DIR)

test :$(NAME)
	./phonebook

re : fclean all

.PHONY: all clean fclean re test\
