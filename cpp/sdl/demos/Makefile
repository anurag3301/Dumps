CXX=g++
CXXFLAGS=-g -Wall -I/usr/include/SDL2 -D_REENTRANT
CXX_LIBS=-lSDL2
TARGETS=demosdl
all: $(TARGETS)

demosdl: window.o
	$(CXX) $(CXXFLAGS) $(CXX_LIBS) $^ -o $@

window.o: window.cpp
	$(CXX) $(CXXFLAGS) $(CXX_LIBS) -c $< -o $@

clean:
	rm -rf *.o $(TARGETS)

run: $(TARGETS)
	clear && ./$(TARGETS)
