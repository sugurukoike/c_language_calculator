CC = gcc
RM = rm

TARGET 	= calc
SRCS 	= calc.c solve.c main.c
OBJS 	= $(SRCS:.c=.o)

HEADER	= calc.h

# ${TARGET} を $@ でも可
${TARGET}: ${OBJS} ${HEADER}
	${CC} -o ${TARGET} -I ${HEADER} ${OBJS}

# ${SRCS} を $^ でも可
${OBJS}: ${SRCS}
	${CC} -c ${SRCS}

all: ${TARGET}

clean:
	${RM} -f ${OBJS}

fclean: clean
	${RM} -f ${TARGET}

re: all fclean
