NAME = philo

SRCS =  ./src/main.c \
	    ./src/actions.c \
		./src/init.c \
		./src/error_exit.c \
		./src/threads.c \
		./src/utils.c \

CC = cc 
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

%.o: %.c ./inc/philo.h Makefile
		${CC} ${CFLAGS} -c $< -o $@	

OBJS = ${SRCS:.c=.o}

all: 
		$(MAKE) ${NAME}

${NAME}:: ${OBJS} $(LIBFT) Makefile
		${CC} $(CFLAGS) $(OBJS) -o ${NAME}

clean:
		${RM} ${OBJS} 

fclean: clean 
		${RM} ${OBJS} ${NAME}

re: 
		$(MAKE) fclean 
		$(MAKE) all

.PHONY: all clean fclean re
