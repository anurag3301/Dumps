C=gcc
CFLAGS=-g -Wall -Wextra `pkg-config --cflags raylib`
LIBS=-lglfw -ldl -lpthread -lm `pkg-config --libs raylib`

OBJS=main.o

all: main

main: $(OBJS)
	$(C) $(CFLAGS) $(LIBS) $(DEFS) -o $@ $(OBJS)

main.o: main.c
	$(C) $(CFLAGS) $(LIBS) $(DEFS) -o $@ -c main.c

run:
	./main

clean:
	rm -f *.o main
