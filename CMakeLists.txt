cmake_minimum_required(VERSION 3.5)

project(GameOfLife LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES  Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
find_package(OpenGL)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)


add_executable(
        GameOfLife
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        Canvas.cpp
        Canvas.h
        model/Life.cpp
        model/Life.h
        panel/Panel.cpp
        panel/Panel.h
        view/Camera.h
        panel/CoordsPanel.cpp
        panel/CoordsPanel.h
        view/Camera.h
        model/Worker.cpp
        model/Worker.h
        view/Camera.cpp
)
target_link_libraries(GameOfLife PRIVATE Qt${QT_VERSION_MAJOR}::Widgets ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} GLEW libGLEW.so)
