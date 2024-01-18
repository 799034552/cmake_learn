cmake_minimum_required(VERSION 3.10)
project(JsonParse)
file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/* include/*)
file(GLOB_RECURSE headers CONFIGURE_DEPENDS include/*)
add_library(JsonParse STATIC ${srcs})
target_include_directories(JsonParse PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)


set(CMAKE_INSTALL_PREFIX "F:/c/C++/install_project")

install(TARGETS JsonParse
    EXPORT JsonParseTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

include(GNUInstallDirs)
# install(DIRECTORY include/ DESTINATION include/)
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT
    JsonParseTargets
    NAMESPACE  "JsonParse::"
    DESTINATION  lib/cmake/JsonParse
)


include(CMakePackageConfigHelpers)

configure_package_config_file(
        ${PROJECT_SOURCE_DIR}/cmake/JsonParseConfig.cmake.in
        ${CMAKE_CURRENT_BINARY_DIR}/JsonParseConfig.cmake
        INSTALL_DESTINATION lib/cmake
        )

install(FILES 
    ${CMAKE_CURRENT_BINARY_DIR}/JsonParseConfig.cmake DESTINATION lib/cmake/JsonParse)

