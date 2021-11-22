add_library (Engine  "Drawable.h" "Drawable.cpp" "Box.cpp" "Box.h")

target_include_directories (Engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
