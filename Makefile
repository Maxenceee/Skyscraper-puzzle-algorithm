CC			=	cc
CFILES		=	sources/main.c sources/generic.c sources/parsing.c sources/solving.c
HEADERS_DIR	=	includes/
CFLAGS		=	-Wall -Wextra -Werror -I $(HEADERS_DIR)
NAME		=	puzzle
OBJS		=	${CFILES:.c=.o}

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADERS_DIR)

all: $(OBJS) $(HEADERS_DIR) Makefile
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re