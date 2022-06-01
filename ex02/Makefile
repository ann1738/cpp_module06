NAME = identify
SRC = main.cpp Base.cpp A.cpp B.cpp C.cpp generate.cpp identify.cpp
OBJ = $(SRC:%.cpp=%.o)
CXX = c++
CPPFLAGS = -Wall -Werror -Wextra -c -std=c++98

all: $(NAME)

$(NAME):$(OBJ)
	$(CXX) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
