
project(netsurl)

set(HEDEAR_FILES NetsUrl.h)
set(SOURCE_FILES NetsUrl.cpp)

add_library(libnetsurl STATIC ${SOURCE_FILES})
target_include_directories(libnetsurl PUBLIC .)

add_executable(netsurl ${SOURCE_FILES} main.cpp)

target_link_libraries(netsurl libnetsurl)

