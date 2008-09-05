SRC_ROOT=.
CFLAGS = -Wall -g
LDFLAGS=-L/usr/local/lib -losg -losgDB -losgViewer
OBJS= main.o scenegraph.o car.o

circledrive: $(OBJS)
	g++ -o circledrive $(LDFLAGS) $(OBJS)

main.o: main.cpp scenegraph.h
	g++ -c $(CFLAGS) main.cpp

scenegraph.o: scenegraph.cpp scenegraph.h
	g++ -c $(CFLAGS) scenegraph.cpp

car.o: car.cpp car.h
	g++ -c $(CFLAGS) car.cpp

clean:
	-rm -f $(OBJS) circledrive 

