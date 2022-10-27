project(PushRelabelService)
find_package(cpprestsdk REQUIRED)
add_executable(PushRelabelService main.cpp BasicController.cpp Graph.cpp PushRelabelController.cpp PushRelabelService.cpp DirectedGraph.cpp utils.cpp)
target_link_libraries(PushRelabelService PUBLIC cpprestsdk::cpprest)