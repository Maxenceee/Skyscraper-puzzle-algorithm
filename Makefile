CFILES		=	sources/main.c sources/generic.c sources/parsing.c sources/solving.c
OBJS		=	${CFILES:.c=.o}
HEADERS_DIR	=	includes/

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -I $(HEADERS_DIR)
NAME		=	puzzle
RM			=	rm -f

%.o: %.c		$(HEADERS_DIR) Makefile
				$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADERS_DIR)

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re