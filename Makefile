NAME =			push_swap
SRCS = 			push_swap.c \

OBJS			= $(SRCS:.c=.o)

HEADER_FILE		= push_swap.h
CFLAGS			= -O3 -Wall -Wextra -Werror -g
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
