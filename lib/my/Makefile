##
## EPITECH PROJECT, 2026
## Makefile
## File description:
## A wonderful file to do automic things !
##

NAME 	=	 libmy.a

CC 		=	 epiclang
CFLAGS 	=	 -Wall -Wextra -Werror

SRC 	= 	$(*.c)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) *.c -c -I../../include/
	ar rc $(NAME) *.o


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o
	rm -rf \#*\#

fclean: clean
	rm -rf *.gcda
	rm -rf *.gcdo

.PHONY: all clean fclean