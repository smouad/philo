NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC =  start.c \
		get_args.c \
		main.c \
		utils.c \

OBJ = $(SRC.c=.o)

all : $(OBJ)
	CC $(CFLAGS) $(SRC) -o $(NAME)