#!/bin/bash
build_baseProject="g++ -o ./bin/main.out ./SDL-GL-GLM/src/*.cpp -lSDL2 -I.//SDL-GL-GLM/include"
build_imgui="g++ -c ./imgui/*.cpp  ./imgui/backends/imgui_impl_opengl3.cpp ./imgui/backends/imgui_impl_sdl2.cpp -I./imgui `sdl2-config --cflags --libs`"

updateCompileCommands()
{
    bear -- $build_baseProject
    bear --append -- $build_imgui
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
    
    mkdir ./obj
    mkdir ./obj/imgui

    echo $build_imgui

    ($build_imgui)

    mv ./*.o ./obj/imgui
    

#build the thing
    echo $build_baseProject
    ($build_baseProject)

    if test ! ./bin/main.out 
    then
        echo "Could not build project"
    fi

}

if  [ "$1" = "update" ]
then
    updateCompileCommands
else
    build
fi