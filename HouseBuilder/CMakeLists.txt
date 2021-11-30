add_library (HouseBuilder Builder.cpp Builder.h UserInputHandler.cpp UserInputHandler.h UserInterfaceRenderer.cpp UserInterfaceRenderer.h)

target_link_libraries(HouseBuilder PUBLIC ConsoleDrawer)
target_include_directories (HouseBuilder PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})