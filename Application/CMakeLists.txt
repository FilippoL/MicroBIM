add_executable (application main.cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Release)

target_link_libraries (application PRIVATE Engine)
target_include_directories(application PUBLIC engine.cpp engine.h)