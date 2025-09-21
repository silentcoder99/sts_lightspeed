cmake_minimum_required(VERSION 3.21)
project(
        sts_lightspeed
        VERSION 0.2
        DESCRIPTION "High Performance, rng accurate implementation of Slay the Spire with tools for tree search and ml."
        LANGUAGES CXX)

file (GLOB_RECURSE STS_SOURCES CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/sts/*.cpp")
file (GLOB_RECURSE STS_TEST_SOURCES CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/sts/*.cpp")

list(FILTER STS_SOURCES EXCLUDE REGEX ".*\\.test\\.cpp")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS  "-Wno-shift-count-overflow -Wno-deprecated -pthread")

find_package(Catch2 3 REQUIRED)

add_executable(tests ${STS_TEST_SOURCES})
target_include_directories(tests PUBLIC ./)
target_include_directories(tests PUBLIC third_party)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

add_executable(benchmark apps/benchmark.cpp ${STS_SOURCES})
target_include_directories(benchmark PUBLIC ./)
target_include_directories(benchmark PUBLIC third_party)

add_executable(battle-sim apps/battle-sim.cpp ${STS_SOURCES})
target_include_directories(battle-sim PUBLIC ./)
target_include_directories(battle-sim PUBLIC third_party)

add_executable(main apps/main.cpp ${STS_SOURCES})
target_include_directories(main PUBLIC ./)
target_include_directories(main PUBLIC third_party)