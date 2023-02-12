C=gcc
CFLAGS=-g -Wall

OBJS=knn.o csv.o

all: knn

knn: $(OBJS)
	$(C) $(CFLAGS) $(DEFS) -o $@ $(OBJS)

knn.o: knn.c csv.h
	$(C) $(CFLAGS) $(DEFS) -o $@ -c knn.c
csv.o: csv.c csv.h
	$(C) $(CFLAGS) $(DEFS) -o $@ -c csv.c

clean:
	rm -f *.o knn
