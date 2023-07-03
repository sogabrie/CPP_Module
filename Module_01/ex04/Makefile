NAME		= replace
	
CC			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

FILES		= main Replace myFile

SRC			= $(FILES:=.cpp)
OBJ			= $(FILES:=.o)
HEADER		= $(wildcard *.hpp)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(HEADER) Makefile
	$(CC) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADER) Makefile
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all