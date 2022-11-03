project(PushRelabelService)
find_package(cpprestsdk REQUIRED)
add_executable(PushRelabelService main.cpp ../Common/BasicController.cpp ../Common/Graph.cpp PushRelabelController.cpp PushRelabelService.cpp ../Common/DirectedGraph.cpp ../Common/KeyboardInterruptHandler.cpp ../Common/utils.cpp)
target_link_libraries(PushRelabelService PUBLIC cpprestsdk::cpprest ssl crypto)