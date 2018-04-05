
project(netstemplateengine)

set(HEDEAR_FILES SimpleTemplateEngine.h)
set(SOURCE_FILES SimpleTemplateEngine.cpp)

add_library(libnetstemplateurl STATIC ${SOURCE_FILES})
target_include_directories(libnetstemplateurl PUBLIC .)

add_executable(netstemplateurl ${SOURCE_FILES} main.cpp)

target_link_libraries(netstemplateurl libnetstemplateurl)

