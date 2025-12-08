NAME1 = fixed

CC = c++
CFLAGS = -Wall -Wextra -Werror

FILES = megaphone.cpp

OBJCT = main.cpp Fixed.cpp

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