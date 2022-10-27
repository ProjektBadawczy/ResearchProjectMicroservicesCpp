project(EdmondsKarpService)
find_package(cpprestsdk REQUIRED)
add_executable(EdmondsKarpService main.cpp BasicController.cpp Graph.cpp EdmondsKarpController.cpp EdmondsKarpService.cpp BFSRequest.cpp BFSResult.cpp utils.cpp)
target_link_libraries(EdmondsKarpService PUBLIC cpprestsdk::cpprest)