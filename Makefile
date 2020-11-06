CC = gcc
LINK_FLAGS = -L$(shell pwd)
BINARY = main

${BINARY}: libcvector.a main.o
	${CC} ${LINK_FLAGS} main.o -l:libcvector.a -o $@

%.o: %.c
	${CC} -c $< -O3

libcvector.a: vla_vec.o
	ar rcs $@ $<

clean:
	rm -rvf *.o *.a *.out ${BINARY}
