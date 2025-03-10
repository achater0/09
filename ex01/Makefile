CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = RPN

SRCS = main.cpp RPN.cpp

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp RPN.hpp
	$(CC) $(CFLAGS)  -c $< -o $@


clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all