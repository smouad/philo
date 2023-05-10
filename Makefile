NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

SRC =  start.c \
		get_args.c \
		philo.c \
		utils.c \
		print_utils.c \

OBJ = $(SRC.c=.o)

all : $(OBJ)
	CC $(CFLAGS) $(SRC) -o $(NAME) 