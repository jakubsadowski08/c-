
project(iterable)

set(HEDEAR_FILES Iterable.h)
set(SOURCE_FILES Iterable.cpp)

add_library(libiterable STATIC ${SOURCE_FILES})
target_include_directories(libiterable PUBLIC .)



