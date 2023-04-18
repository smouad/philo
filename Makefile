NAME = philoo

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC =  start.c \
		get_args.c

OBJ = $(SRC.c=.o)

all : $(OBJ)
	CC $(CFLAGS) $(SRC) -o $(NAME)