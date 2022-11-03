project(EdmondsKarpService)
find_package(cpprestsdk REQUIRED)
add_executable(EdmondsKarpService main.cpp ../Common/BasicController.cpp ../Common/Graph.cpp EdmondsKarpController.cpp EdmondsKarpService.cpp ../Common/BFSRequest.cpp ../Common/BFSResult.cpp ../Common/utils.cpp ../Common/KeyboardInterruptHandler.cpp)
target_link_libraries(EdmondsKarpService PUBLIC cpprestsdk::cpprest ssl crypto)