NAME =			checker
VPATH =			./src/
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

INCL_DIR		= ./include/
CFLAGS			= -O3 -Wall -Wextra -Werror -I$(INCL_DIR)
LIBFT_DIR		= ../libft
LIBFT			= ../libft/libft.a
CC				= gcc

all:	$(NAME)

$(NAME): $(LIBFT) $(OBJS)
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT}

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME) $(LIBFT)

re:	fclean $(NAME)

.PHONY: all clean fclean re
