#!/bin/bash
build_command="g++ -o ./bin/main.out ./src/*.cpp -lSDL2 -I./include"

updateCompileCommands()
{
    bear -- $build_command
}

build ()
{
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

#build the thing
    echo $build_command
    ($build_command)

    if test ! ./bin/main.out 
    then
        echo "Could not build project"
    fi
}

if  [ "$1" = "build" ]
then
    echo $1
    echo "building:"
    build
fi


if  [ "$1" = "update" ]
then
    updateCompileCommands
fi
