project( lib )

add_library(
    lib
    Logger/logger.h
    Logger/logger.cpp
)

target_include_directories( lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIRECTORY}" )
