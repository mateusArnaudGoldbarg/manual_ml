#!/bin/bash

g++ -c model.cpp
g++ -c iris.cpp
g++ -c main.cpp

g++ model.o iris.o main.o -o program
./program
