NAME = span

CC = c++

FLAGS	= -Wall -Wextra -Werror -std=c++98

RM = rm -rf

SRC = main.cpp Span.cpp

all : $(NAME)

$(NAME) : $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean :
	$(RM) $(NAME)

fclean :
	$(RM) $(NAME)

re : clean all