C=gcc
CFLAGS=-g -Wall -Wextra `pkg-config --cflags raylib`
LIBS=-lglfw -ldl -lpthread -lm `pkg-config --libs raylib`

OBJS=music.o

all: music

music: $(OBJS)
	$(C) $(CFLAGS) $(LIBS) $(DEFS) -o $@ $(OBJS)

music.o: music.c
	$(C) $(CFLAGS) $(LIBS) $(DEFS) -o $@ -c music.c

clean:
	rm -f *.o music
