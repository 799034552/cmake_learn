cmake_minimum_required(VERSION 3.1)
# project(my_project)

file(GLOB_RECURSE srcs src/*.cpp include/*.h)
add_executable(my_project)

target_sources(my_project
    PRIVATE
    ${srcs}
)

target_link_libraries(my_project PUBLIC Request)


