add_executable(HouseBuilder main.cpp)
target_include_directories(HouseBuilder PUBLIC ../ConsoleDrawer)
target_sources(HouseBuilder PUBLIC Builder.cpp Builder.h UserInputHandler.h UserInputHandler.cpp UserInterfaceRenderer.cpp UserInterfaceRenderer.h House.cpp House.h Door.cpp Door.h Window.cpp Window.h)
