#!/bin/bash
if test -d ./bin 
then
    rm -rf --dir ./bin/*
    rm -rf --dir ./bin
    if test -d ./bin 
    then
        echo "could not delete bin folder and contents"
    fi
fi
 
 mkdir ./bin

 g++ -o ./bin/main.out ./src/*.cpp -lSDL2

 if test ! ./bin/main.out 
 then
    echo "Could not build project"
fi