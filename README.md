# Marciano-Game-II
Game created as a project for TP subject. 
The goal in the game is to reach the highest punctuation by collecting stars.

The GUI is created using *Pantalla* wrapper, given in the subject.

## Compile & run
To compile the game just run:  
```sh
$ make
```  

Once compiled the executable file is prepared and you can play the game by running:
```sh
$ ./run
```

In order to play the game with a certain resolution you can specify it via command line:
```sh
# ./run width height
$ ./run 1280 960
```

## Clean

If you want to erase all generated files run:
```sh
$ make clean
```  

## Requirements
The game needs the system to have installed the following:
* SDL2 Library
* GNU Make
* GCC Compiler
* XLib11

```bash
sudo apt install gcc make libsdl2-dev -y
```