NAME = philoo

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC =  start.c \
		check_input.c

OBJ = $(SRC.c=.o)

all : $(OBJ)
	CC $(CFLAGS) $(SRC) -o $(NAME)