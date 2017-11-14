CFLAGS=-O2
PROGRAMS=n_queens

all: ${PROGRAMS}


n_queens: n_queens.h n_queens.c n_queens_main.c
	${CC} ${CFLAGS} n_queens.c n_queens_main.c -o n_queens

clean:
	rm -f ${PROGRAMS}


