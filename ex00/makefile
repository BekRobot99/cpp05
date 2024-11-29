C++ = c++
FLAGS = -Wall -Wextra -Werror -std=c++17 -pedantic
FILES = 	main.cpp Bureaucrat.cpp

OBJ = $(FILES:.cpp=.o)

NAME = bureaucrat

all: $(NAME)

$(NAME):$(OBJ)
	$(C++) $(FLAGS) $(OBJ) -o $(NAME) 

%.o: %.cpp
	$(C++) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re