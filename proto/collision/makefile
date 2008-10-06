SRC_ROOT = .
CFLAGS  = -Wall -g
LDFLAGS = -L/usr/local/lib -losg -losgDB -losgViewer
OBJS = main.o car.o

collision: $(OBJS)
	g++ -o collision $(LDFLAGS) $(OBJS)

main.o: main.cpp car.h 
	g++ -c $(CFLAGS) main.cpp

car.o: car.cpp car.h
	g++ -c $(CFLAGS) car.cpp

clean:
	-rm -f $(OBJS) collision 

