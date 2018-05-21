
project(algo)

set(HEDEAR_FILES Algo.h)
set(SOURCE_FILES Algo.cpp)

add_library(libalgo STATIC ${SOURCE_FILES})
target_include_directories(libalgo PUBLIC .)



