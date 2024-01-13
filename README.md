# Marciano-Game-II

![Marciano Game II Logo](logo.png)

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

## Install
> Note: This feature is in progress.

You can compile the application and create a desktop icon all in one. Run:

```sh
$ sudo make install
$ sudo make uninstall
```

This creates/removes a desktop icon and the binary at `/usr/bin`.

## Requirements
The game needs the system to have installed the following:
* SDL2 Library
* GNU Make
* GCC Compiler
* XLib11

```bash
sudo apt install gcc make libsdl2-dev -y
```