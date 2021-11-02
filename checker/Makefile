NAME =			checker
SRCS = 			checker.c	\
				push.c		\
				swap.c		\
				rotate.c	\
				r_rotate.c	\
				gets_and_checks.c \
				exit.c		\
				gnl/get_next_line.c	\
				gnl/get_next_line_utils.c	\



OBJS			= $(SRCS:.c=.o)

HEADER_FILE		= checker.h
CFLAGS			= -O3 -Wall -Wextra -Werror -I.
LIBFT			= ../libft/libft.a
CC				= gcc

all:	$(NAME)

$(NAME): $(LIBFT) $(OBJS)
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS} ${LIBFT}

$(LIBFT):
	make -C ../libft

clean:
	make clean -C ../libft
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME) $(LIBFT)

re:	fclean $(NAME)

.PHONY: all clean fclean re
