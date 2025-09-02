NAME = rush-02
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes
SRCS = srcs/main.c srcs/aux_ft.c srcs/create_dict.c\
       srcs/dict.c srcs/format.c srcs/ft_split.c\
       srcs/is_valid_num.c srcs/manual_split.c srcs/print_num.c
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
