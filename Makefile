
asteroids: main.o glFunctions.o GameObject.o Spaceship.o Arena.o math.o Position.o
	g++ *.o -lglut -lGLU -lGL -o asteroids

main.o: main.cpp
	g++ -c main.cpp

glFunctions.o: glFunctions.cpp
	g++ -c glFunctions.cpp

GameObject.o: GameObject.cpp
	g++ -c GameObject.cpp

Spaceship.o: Spaceship.cpp
	g++ -c Spaceship.cpp

Arena.o: Arena.cpp
	g++ -c Arena.cpp
	
math.o: math.cpp
	g++ -c math.cpp

Position.o: Position.cpp
	g++ -c Position.cpp

clean:
	rm *.o asteroids
