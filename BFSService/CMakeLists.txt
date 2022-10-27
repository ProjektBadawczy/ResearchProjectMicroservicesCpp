project(BFSService)
find_package(cpprestsdk REQUIRED)
add_executable(BFSService main.cpp BasicController.cpp Graph.cpp BFSController.cpp BFSService.cpp BFSRequest.cpp BFSResult.cpp utils.cpp)
target_link_libraries(BFSService PUBLIC cpprestsdk::cpprest)