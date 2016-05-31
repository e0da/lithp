CC = clang
CCOPTS = -g -std=c99 -Wall
BINS = hello_world prompt parsing

all: ${BINS}

prompt: prompt.c
	${CC} ${CCOPTS} -ledit prompt.c -o prompt

parsing: parsing.c mpc.c
	${CC} ${CCOPTS} -ledit -lm -o parsing parsing.c mpc.c

hello_world: hello_world.c
	${CC} ${CCOPTS} hello_world.c -o hello_world

clean:
	rm -f ${BINS}
