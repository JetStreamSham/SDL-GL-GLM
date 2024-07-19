#!/bin/bash
build_baseProject="g++ -o ./bin/main.out ./SDL-GL-GLM/src/*.cpp -lSDL2 -I.//SDL-GL-GLM/include -I./imgui"
build_imgui="g++ -c ./imgui/*.cpp  ./imgui/backends/imgui_impl_opengl3.cpp ./imgui/backends/imgui_impl_sdl2.cpp -I./imgui `sdl2-config --cflags --libs`"

build ()
{

    mkdir ./bin    
    mkdir ./obj
    mkdir ./obj/imgui

    echo $build_imgui

    if hash bear
    then
        bear --append -- $build_imgui
    else 
        ($build_imgui)
    fi

    mv ./*.o ./obj/imgui
    
#build the thing
    echo $build_baseProject

    if hash bear
    then
        bear --append -- $build_baseProject
    else 
        ($build_baseProject)
    fi

    if test ! ./bin/main.out 
    then
        echo "Could not build project"
    fi

}

build