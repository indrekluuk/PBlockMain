cmake_minimum_required(VERSION 3.2)
project(PBlockMain)


# For CLion to properly recognize library headers
include_directories(src/lib/PBlocksDisplay)

# For CLion to properly recognize library source files
aux_source_directory(src/lib/PBlocksDisplay SRC_LIST)
list(APPEND SRC_LIST src/PBlocksMain/PBlocksMain.ino)
# remove "src/" prefix from file names
string(REGEX REPLACE "src[\\/\\\\]" "" SRC_LIST "${SRC_LIST}")

# PlatformIO build targets
# Must init platformio. See: PlatformIO_CLion_init.txt
add_subdirectory(src)






# init Google Test target
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# fake arduino headers
include_directories(test/fake)
# project headers
include_directories(src/lib/PBlocksDisplayElements)
include_directories(src/lib/PBlocksProgram)
include_directories(src/PBlocksMain)
# gtest headers
include_directories(${gtest_SOURCE_DIR}/include)


add_executable(runTests
        test/fake/Arduino.cpp
        test/fake/avr/pgmspace.cpp

        src/lib/PBlocksDisplay/TouchHandler.cpp
        src/lib/PBlocksDisplay/PBlocksDisplay.cpp
        src/lib/PBlocksDisplay/Sheet.cpp
        src/lib/PBlocksDisplay/TFT.cpp
        src/lib/PBlocksDisplayElements/ProgMemIcons.cpp
        src/lib/PBlocksProgram/PBlocksProgram.cpp
        src/lib/PBlocksProgram/ProgramNode.cpp


        test/src/PBlocksDisplay/TestTouchRegion.cpp
        )

# link
add_subdirectory(test/lib/gtest-1.7.0)
target_link_libraries(runTests gtest_main)





