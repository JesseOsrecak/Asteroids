
play: main.o
	g++ main.o -lglut -lGLU -lGL -o play

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o play