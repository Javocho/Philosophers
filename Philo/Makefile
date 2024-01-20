NAME = philo

SRCS = ./src/philo.c \
	    ./src/utils.c \
		./src/threads.c \
		./src/init.c \
		./src/eat_print.c

LIBFT					:=	./libs/libft/

LIBS				 	:= $(LIBFT)/libft.a

CC = cc 
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

%.o: %.c ./inc/philo.h Makefile $(LIBS)
		${CC} ${CFLAGS} -c $< -o $@	

OBJS = ${SRCS:.c=.o}

all: 
		@$(MAKE) -C $(LIBFT)
		$(MAKE) ${NAME}

${NAME}:: ${OBJS} $(LIBFT) Makefile
		${CC} $(CFLAGS) $(OBJS) -o ${NAME}

clean:
		${RM} ${OBJS} 
		@$(MAKE) -C $(LIBFT) clean

fclean: clean 
		@$(MAKE) -C $(LIBFT) fclean
		${RM} ${OBJS} ${NAME}

re: 
		$(MAKE) fclean 
		$(MAKE) all

.PHONY: all clean fclean re