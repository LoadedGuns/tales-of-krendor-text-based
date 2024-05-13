@echo off
SET CC=gcc
SET CXX=g++
SET CFLAGS=-Wall -Wextra
SET CXXFLAGS=-Wall -Wextra
SET LDFLAGS=
SET OBJ=main.o player.o gear.o goblin.o orc.o combat.o functions.o fishing.o inventory.o
SET OUT=game

echo Compiling C files...
%CC% -c playerdata/player.c -o player.o %CFLAGS%
%CC% -c gear/gear.c -o gear.o %CFLAGS%
%CC% -c npcs/goblin/goblin.c -o goblin.o %CFLAGS%
%CC% -c npcs/orc/orc.c -o orc.o %CFLAGS%
%CC% -c combat/combat.c -o combat.o %CFLAGS%
%CC% -c functions/functions.c -o functions.o %CFLAGS%
%CC% -c skills/fishing/fishing.c -o fishing.o %CFLAGS%
%CC% -c main.c -o main.o %CFLAGS%

echo Compiling C++ files...
%CXX% -c inventory/inventory.cpp -o inventory.o %CXXFLAGS%

echo Linking...
%CXX% -o %OUT% main.o player.o gear.o goblin.o orc.o combat.o functions.o fishing.o inventory.o %LDFLAGS%

echo Clean up object files...
del *.o

echo Done.
