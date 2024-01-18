file(GLOB_RECURSE srcs src/* include/*)
add_library(Request
STATIC
${srcs})

target_include_directories(Request PUBLIC include)
target_link_libraries(
    Request
    PUBLIC
    JsonParse
)


