add_executable (UserSide main.cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Release)

target_link_libraries (UserSide PUBLIC ConsoleDrawer HouseBuilder)
target_include_directories(UserSide PUBLIC ConsoleDrawer HouseBuilder)