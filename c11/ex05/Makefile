NAME = do-op
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes
SRCS = srcs/main.c srcs/operators.c srcs/aux_ft.c
       
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $@

%.o: %.c
	$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
