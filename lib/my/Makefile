##
## EPITECH PROJECT, 2026
## Makefile
## File description:
## This file is responsible of compiling the library
##

SRC				=	$(wildcard *.c)
OBJ				=	$(SRC:.c=.o)

NAME			=	libmy.a

CC				=	epiclang
CFLAGS			=	-I../../include
CCFLAGS			=	-Wall -Wextra -Werror

LIBRARY_VERSION_MAJOR := 2
LIBRARY_VERSION_MINOR := 0
LIBRARY_VERSION_PATCH := 5
LIBRARY_VERSION := $(LIBRARY_VERSION_MAJOR).$(LIBRARY_VERSION_MINOR).$(LIBRARY_VERSION_PATCH)

CFLAGS += -DLIBRARY_VERSION=\"$(LIBRARY_VERSION)\"
CFLAGS += -DLIBRARY_VERSION_MAJOR=$(LIBRARY_VERSION_MAJOR)
CFLAGS += -DLIBRARY_VERSION_MINOR=$(LIBRARY_VERSION_MINOR)
CFLAGS += -DLIBRARY_VERSION_PATCH=$(LIBRARY_VERSION_PATCH)

all: $(NAME)

$(NAME): $(OBJ)
	$(info === Compiling library libmy version v$(LIBRARY_VERSION) ===)
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