# Asteroids

## Author: Jesse Osrecak


## Make

### Compile
To comepile the code you can use the make file for easy compilation. Use the following command in the terminal.

`make`

This will compile all the files and make output files. Following it will create the file 'asteroids'.

### Clear
In order to remove all the compilation files you can use the following command:

`make clean`

This will run the following command:

`rm *.o asteroids`

This deletes all files that end in '.o' and the 'asteroids' file

### Configuration
Configuring the Makefile is quite simple it follows the format:

`target: dependicies
    action`

The line that begins with: 

`asteroids` 

Is the linking command which takes all of the '.o' files as dependcies and will link them together in to the 'asteroids' file.

For each output file there there needs to be a compilation beforehand for instance the file 'main.cpp' would need
`main.o: main.cpp
    g++ -c main.cpp`

## Running the game
In order to run the game you must compile the game first see Make -> Compile above for compilation instructions. 

Once Compiled to run the game type into terminal:

 `./asteroids`

## Class Breakdown

### main.cpp
    main.cpp is the main file. This file is what stores the code for running the program.
    This also houses the code for creating the window.

### glFunctions.cpp
    glFunctions is a helper file for the main.cpp file. This houses functions used by openGl to draw, readjust and keybindings.3

### GameObject.cpp
    GameObject.cpp is a parent class used for the tracking of the a Game objects standard variables such as Location. This class is not intended to be instansiated. Whilst it can be.
