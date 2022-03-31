
play.exe: main.o
	g++ main.o -lglut -lGLU -lGL -o play.exe

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o play.exe
