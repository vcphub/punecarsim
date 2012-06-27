SRC_ROOT=.
CFLAGS = -Wall -g
LDFLAGS=-lOpenThreads -losg -losgDB -losgUtil -losgGA -losgText -losgViewer 
OBJS= main.o scenegraph.o car.o

circledrive: $(OBJS)
	g++ -o circledrive $(OBJS) $(LDFLAGS) 

main.o: main.cpp scenegraph.h
	g++ -c $(CFLAGS) main.cpp

scenegraph.o: scenegraph.cpp scenegraph.h
	g++ -c $(CFLAGS) scenegraph.cpp

car.o: car.cpp car.h
	g++ -c $(CFLAGS) car.cpp

clean:
	-rm -f $(OBJS) circledrive 

