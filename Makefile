CC				= c++
FLAGS			= -Wall -Wextra -Werror -g
INCLUDE			= -I ./includes -I ./src/tests
SRC_DIR			= ./src
SRCS			+= $(addprefix  $(SRC_DIR)/, \
						SimulatedAnnealing.cpp \
						AProblem.cpp \
						)

TESTS_SRC		+= $(addprefix  $(SRC_DIR)/tests/, \
						TSProblem.cpp \
						tsp.cpp)
TEST_OBJS		= $(TESTS_SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

OBJS			= $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
OBJ_DIR 		= ./obj
NAME			= libsa-cpp.a

all : $(NAME) salesman

$(OBJS) $(TEST_OBJS): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) $(INCLUDE) -o $@ -c $<

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

salesman: $(NAME) $(TEST_OBJS)
	$(CC) $(FLAGS) $(INCLUDE) $(TEST_OBJS) -o salesman $(NAME)

clean :
	rm -rf ./obj 

fclean : clean
	rm -f salesman

re : fclean all

.PHONY :
	clean fclean re all