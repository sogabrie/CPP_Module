NAME	= hi_this_is_brain

CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98
RM		= rm -rf

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): main.cpp Makefile
	$(CC) $(FLAGS) main.cpp -o $(NAME)

clean:
	$(RM) $(NAME)

fclean:
	$(RM) $(NAME)

re: fclean all