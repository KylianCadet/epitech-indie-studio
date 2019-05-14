##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

NAME = test

CC = g++

SRCS =	test.cpp \

SRCDIR = ./src/

OBJS = $(addprefix $(SRCDIR), $(SRCS:.c=.o))

WFLAGS = -Wextra -Wall -Werror

INCLUDES = -I./include

LIB =

LINK = -lIrrlicht -lGL -lXxf86vm -lXext -lX11

CFLAGS += $(WFLAGS) $(INCLUDES) $(LIB)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LINK)

clean:
	rm -f src/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re