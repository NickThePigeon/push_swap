NAME =			push_swap
SRCS = 			src/push_swap.c \
				src/parse.c		\
				src/push.c		\
				src/swap.c		\
				src/r_rotate.c	\
				src/rotate.c	\
				src/algorithms.c	\
				src/utils.c		\
				src/exit.c		\


OBJS			= $(SRCS:.c=.o)

HEADER_FILE		= push_swap.h
CFLAGS			= -O3 -Wall -Wextra -Werror -I.
LIBFT			= libft/libft.a
CC				= gcc

all:	$(NAME)

$(NAME): $(LIBFT) $(OBJS)
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS} ${LIBFT}

$(LIBFT):
	make -C libft

clean:
	make clean -C libft
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME) $(LIBFT)

re:	fclean $(NAME)

.PHONY: all clean fclean re
