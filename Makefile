NAME = philo

CC = cc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

SRC =  ft_init.c \
		ft_routine.c \
		philo.c \
		ft_print.c \
		ft_utils.c

OBJ = $(SRC:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
