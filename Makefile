NAME =			push_swap
VPATH =			./src/
SRCS = 			push_swap.c \
				parse.c		\
				push.c		\
				swap.c		\
				r_rotate.c	\
				rotate.c	\
				algorithms.c	\
				utils.c		\
				exit.c		\
				gets_and_checks.c	\

OBJS			= $(SRCS:.c=.o)
INCL_DIR		= ./include/
CFLAGS			= -O3 -Wall -Wextra -Werror -I$(INCL_DIR)
LIBFT			= libft/libft.a
CC				= gcc

all:	$(NAME)

$(NAME): $(LIBFT) $(OBJS)
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT}

$(LIBFT):
	make -C libft

clean:
	make clean -C libft
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME) $(LIBFT)

re:	fclean $(NAME)

.PHONY: all clean fclean re
