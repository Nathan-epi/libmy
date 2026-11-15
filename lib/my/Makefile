##
## EPITECH PROJECT, 2026
## Makefile
## File description:
## This file is responsible of compiling the library
##

SRC		=	$(wildcard basic/*.c) \
			$(wildcard my_put_error/*.c) \
			$(wildcard my_printf/*.c)
OBJ		=	$(SRC:.c=.o)

NAME	=	libmy.a

CC		=	epiclang
CFLAGS	=	-I../../include
CCFLAGS	=	-Wall -Wextra -Werror

LIBRARY_VERSION = v2.1.0

all: $(NAME)

$(NAME): $(OBJ)
	$(info === Compiling library libmy version $(LIBRARY_VERSION) ===)
	ar rc $(NAME) $(OBJ)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS) $(CCFLAGS)

clean:
	rm -f $(OBJ)
	rm -rf *.gcda *.gcno

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re