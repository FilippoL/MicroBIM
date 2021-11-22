add_executable (Application main.cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Release)

target_link_libraries (Application PRIVATE Engine)
target_include_directories(Application PUBLIC Engine)