CC              = c++
FLAGS           = -Wall -Wextra -Werror -g
INCLUDE         = -I ./includes -I ./tests
SRC_DIR 		 = ./src
SRCS            += $(addprefix  $(SRC_DIR)/, \
						SimulatedAnnealing.cpp \
						TSProblem.cpp \
						AProblem.cpp \
						main.cpp)
OBJS             = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
OBJ_DIR 		 = ./obj

all : salesman

$(OBJS) : $(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $(INCLUDE) -o $@ -c $<

salesman: $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o salesman

clean :
	rm -rf ./obj 

fclean : clean
	rm -f salesman

re : fclean all

.PHONY :
	clean fclean re all