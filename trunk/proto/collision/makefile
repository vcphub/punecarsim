SRC_ROOT=.
CFLAGS = -Wall -g
LDFLAGS=-L/usr/local/lib -losg -losgDB -losgViewer
OBJS= main.o 

collision: $(OBJS)
	g++ -o collision $(LDFLAGS) $(OBJS)

main.o: main.cpp 
	g++ -c $(CFLAGS) main.cpp

clean:
	-rm -f $(OBJS) collision 

