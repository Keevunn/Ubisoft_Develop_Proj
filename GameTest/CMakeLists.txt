cmake_minimum_required(VERSION 3.26)
project(GameTest)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(App)
include_directories(glut)
include_directories(glut/include)
include_directories(glut/include/GL)
include_directories(stb_image)

add_executable(GameTest
        App/app.cpp
        App/app.h
        App/AppSettings.h
        App/DirectSound.cpp
        App/DirectSound.h
        App/main.cpp
        App/main.h
        App/mydirectsound.h
        App/SimpleController.cpp
        App/SimpleController.h
        App/SimpleSound.cpp
        App/SimpleSound.h
        App/SimpleSprite.cpp
        App/SimpleSprite.h
        glut/include/GL/freeglut.h
        glut/include/GL/freeglut_ext.h
        glut/include/GL/freeglut_std.h
        glut/include/GL/glut.h
        stb_image/stb_image.cpp
        stb_image/stb_image.h
        GameTest.cpp
        stdafx.cpp
        stdafx.h
        targetver.h)
