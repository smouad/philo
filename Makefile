NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g

SRC =  ft_init.c \
		ft_routine.c \
		philo.c \
		ft_print.c \

OBJ = $(SRC.c=.o)

all : $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) 