cmake_minimum_required(VERSION 3.8)

project(M10EP-awrigh30)

set(CMAKE_CXX_STANDARD 14)

add_executable(M20EP-awrigh30
        main.cpp
        PlayGame.cpp
        PlayGame.h
        Dont_Build_The_Man.cpp
        Dont_Build_The_Man.h
        Player.cpp
        Player.h
        Level.cpp
        Level.h
)
add_executable(test
        PlayGame.cpp
        PlayGame.h
        Dont_Build_The_Man.cpp
        Dont_Build_The_Man.h
        Player.cpp
        Player.h
        Level.cpp
        Level.h
        test.cpp
)