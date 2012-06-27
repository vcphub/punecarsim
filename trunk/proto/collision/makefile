SRC_ROOT = .
CFLAGS  = -Wall -g
#LDFLAGS = -L/usr/local/lib -losg -losgDB -losgViewer
LDFLAGS=-lOpenThreads -losg -losgDB -losgUtil -losgGA -losgText -losgViewer 
OBJS = main.o car.o

collision: $(OBJS)
	g++ -o collision $(OBJS) $(LDFLAGS) 

main.o: main.cpp car.h 
	g++ -c $(CFLAGS) main.cpp

car.o: car.cpp car.h
	g++ -c $(CFLAGS) car.cpp

clean:
	-rm -f $(OBJS) collision 

