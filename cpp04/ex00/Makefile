NAME1 = animal

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

FILES = main.cpp Animal.cpp Dog.cpp Cat.cpp

OBJCT = main.o Animal.o Dog.o Cat.o

all: $(NAME1)

$(NAME1): $(OBJCT)
	$(CC) $(CFLAGS) $(OBJCT) -o $(NAME1)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJCT)

fclean: clean
	rm -f $(NAME1)

re: fclean all

.PHONY: all clean fclean re