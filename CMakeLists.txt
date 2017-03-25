cmake_minimum_required(VERSION 3.2)
project(PBlockMain)


# For CLion to properly recognize library heders
include_directories(src/lib/Adafruit_GFX_Library)
include_directories(src/lib/MCUFRIEND_kbv)
include_directories(src/lib/Touch-Screen-Library)
include_directories(src/lib/PBlocksDisplay)

# For CLion to properly recognize library source files
aux_source_directory(src/lib/PBlocksDisplay SRC_LIST)
# remove "src/" prefix from file names
string(REGEX REPLACE "src[\\/\\\\]" "" SRC_LIST "${SRC_LIST}")

# PlatformIO build targets
# Must init platformio. See: PlatformIO_CLion_init.txt
add_subdirectory(src)






# init Google Test target
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# fake arduino headers
#include_directories(test/fake)
# project headers
include_directories(src/PBlocksMain)
# gtest headers
#include_directories(${gtest_SOURCE_DIR}/include)


#add_executable(runTests)

# link
#add_subdirectory(test/lib/gtest-1.7.0)
#target_link_libraries(runTests gtest_main)





