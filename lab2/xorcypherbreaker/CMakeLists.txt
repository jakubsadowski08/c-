
project(xorcrypterbreaker)

set(HEDEAR_FILES XorCypherBreaker.h)
set(SOURCE_FILES XorCypherBreaker.cpp)

add_library(libxorcrypterbreaker STATIC ${SOURCE_FILES})
target_include_directories(libxorcrypterbreaker PUBLIC .)

add_executable(xorcrypterbreaker ${SOURCE_FILES} main.cpp)

target_link_libraries(xorcrypterbreaker libxorcrypterbreaker)

