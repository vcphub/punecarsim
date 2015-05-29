This project will develop a car/vehicle driving simulator. Simulator will consists of software and hardware components.
  * The integrated system will realistically simulate actual experience of driving a specific vehicle on a specific route.
  * The simulator will be used by people learning to safely drive a car in different traffic conditions.
  * The simulator will also guide/teach user to learn safe driving, by talking to used in his/her language.
  * The simulator will monitor the performance of the user and determine driving skill level/score of the user and suggest areas of improvement.

Hopefully this project will help reducing number of accidents due to improper/insufficient driving skills.

You can download source of prototype software, which will be building blocks for actual system. One such prototype us 'circledrive'. This program allows you to drive on the a circular road using LEFT, RIGHT, UP and DOWN buttons on the keypad (make sure you turn on the keypad).

LEFT = Steer LEFT
RIGHT = Steer RIGHT
UP = Accelerate i.e increase speed.
DOWN = De-accelerate i.e decrease speed.

```

$ make
g++ -c -Wall -g main.cpp
g++ -c -Wall -g scenegraph.cpp
g++ -c -Wall -g car.cpp
g++ -o simroad -L/usr/local/lib -losg -losgDB -losgViewer main.o scenegraph.o car.o

```

Following are screenshots of some prototypes:

**Drive on circular road:**

http://punecarsim.googlegroups.com/web/circledrive.png?gsc=KoNBdQsAAADBHnTA60oCstk5azPrgvSk

**Collision Detection:**

http://punecarsim.googlegroups.com/web/collision.png?gsc=KoNBdQsAAADBHnTA60oCstk5azPrgvSk