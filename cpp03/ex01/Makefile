NAME = scavtrap

OBJ_DIR = objs/
SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp
OBJ := $(SRCS:.cpp=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

$(OBJ_DIR)%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

clean:
	rm -f $(OBJS)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)
