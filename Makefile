CC = clang
CCOPTS = -g -std=c99 -Wall
BINS = hello_world prompt

all: ${BINS}

prompt: prompt.c
	${CC} ${CCOPTS} -ledit prompt.c -o prompt

hello_world: hello_world.c
	${CC} ${CCOPTS} hello_world.c -o hello_world

clean:
	rm -f ${BINS}
