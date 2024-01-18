cmake_minimum_required(VERSION 3.10)
project(main)
set(CMAKE_PREFIX_PATH  "F:/c/C++/install/Qt6.2.7-Windows-x86_64-MinGW11.2.0-staticFull;F:/c/C++/install/opencv_static")
# set(CMAKE_PREFIX_PATH  "E:/Qt_static;F:/c/C++/install/opencv_static")
set(CMAKE_BUILD_TYPE Release)
set(OpenCV_STATIC ON)
set(CMAKE_EXE_LINKER_FLAGS "-static")
find_package(OpenCV REQUIRED )
find_package(Qt6 REQUIRED COMPONENTS Widgets)


add_executable(main WIN32)
target_sources(main
    PUBLIC
    main.cpp)
    

target_link_libraries(main
    PRIVATE 
    ${OpenCV_LIBS} "-static")

target_link_libraries(main
    PRIVATE 
    Qt6::Widgets "-static")

