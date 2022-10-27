project(GraphService)
find_package(cpprestsdk REQUIRED)
add_executable(GraphService main.cpp BasicController.cpp DirectedGraph.cpp Graph.cpp GraphController.cpp GraphRepository.cpp GraphService.cpp)
target_link_libraries(GraphService PUBLIC cpprestsdk::cpprest)