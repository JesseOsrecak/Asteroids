
asteroids: main.o glFunctions.o GameObject.o Spaceship.o
	g++ *.o -lglut -lGLU -lGL -o asteroids

main.o: main.cpp
	g++ -c main.cpp

glFunctions.o: glFunctions.cpp
	g++ -c glFunctions.cpp

GameObject.o: GameObject.cpp
	g++ -c GameObject.cpp

Spaceship.o: Spaceship.cpp
	g++ -c Spaceship.cpp
clean:
	rm *.o asteroids
