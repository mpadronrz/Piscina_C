NAME = bsq
SOURCES =  srcs/aux_ft.c srcs/ft_split.c srcs/solve.c srcs/write_map.c \
	   srcs/create_map.c srcs/main.c srcs/validate_map.c
INCLUDES = -I includes
OBJECTS = $(SOURCES:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

clean: 
	rm -f $(OBJECTS)
fclean: clean
	rm -f $(NAME)

re: fclean all
