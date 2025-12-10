NAME1 = fragtrap

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

FILES = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

OBJCT = main.o ClapTrap.o ScavTrap.o FragTrap.o

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