
asteroids: main.o glFunctions.o GameObject.o Spaceship.o Arena.o math.o Position.o CollissionBox.o collission_test.o helper.o Gun.o Bullet.o 
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

CollissionBox.o: CollissionBox.cpp
	g++ -c CollissionBox.cpp

collission_test.o: tests/collission_test.cpp
	g++ -c tests/collission_test.cpp

helper.o: helper.cpp
	g++ -c helper.cpp

Gun.o: Gun.cpp
	g++ -c Gun.cpp

Bullet.o: Bullet.cpp
	g++ -c Bullet.cpp

# Vector.o: Vecotr.cpp
# 	g++ -c Vector.cpp

clean:
	rm *.o asteroids
