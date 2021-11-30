add_library (ConsoleDrawer "Line.h" "Line.cpp" "Shape.h" "Shape.cpp" "Box.cpp" "Box.h" "Circle.h" "Circle.cpp" "ConsoleCanvas.h" "ConsoleCanvas.cpp" "DataStructures.h")

target_include_directories (ConsoleDrawer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
