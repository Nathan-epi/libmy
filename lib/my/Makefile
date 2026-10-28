##
## EPITECH PROJECT, 2026
## Makefile
## File description:
## This file is responsible of compiling the library
##

SRC		=	*.c
NAME 	=	libmy.a

CC 		=	epiclang
CFLAGS	=	-I../../include/
CCFLAGS =	-Wall -Wextra -Werror

all:
	$(CC) $(SRC) -c $(CFLAGS) $(CCFLAGS)
	ar rc $(NAME) *.o
	rm -rf *.o

clean:
	rm -rf *.o

fclean: clean
	rm -rf *.a *.out *.gcda *.gcdo

re : fclean

.PHONY: all clean fclean re