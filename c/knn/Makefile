C=gcc
CFLAGS=-g -Wall
LIBS=-lm

OBJS=knn.o csv.o

all: knn

knn: $(OBJS)
	$(C) $(CFLAGS) $(LIBS) $(DEFS) -o $@ $(OBJS)

knn.o: knn.c csv.h
	$(C) $(CFLAGS) $(LIBS) $(DEFS) -o $@ -c knn.c
csv.o: csv.c csv.h
	$(C) $(CFLAGS) $(LIBS) $(DEFS) -o $@ -c csv.c

clean:
	rm -f *.o knn
