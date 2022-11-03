project(GraphService)
find_package(cpprestsdk REQUIRED)
add_executable(GraphService main.cpp ../Common/BasicController.cpp ../Common/DirectedGraph.cpp ../Common/Graph.cpp GraphController.cpp GraphRepository.cpp GraphService.cpp ../Common/KeyboardInterruptHandler.cpp)
target_link_libraries(GraphService PUBLIC cpprestsdk::cpprest ssl crypto)