file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/* include/*)
add_library(JsonParse STATIC ${srcs})
target_include_directories(JsonParse PUBLIC include)