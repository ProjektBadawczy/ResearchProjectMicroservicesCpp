project(BFSService)
find_package(cpprestsdk REQUIRED)
add_executable(BFSService main.cpp ../Common/BasicController.cpp ../Common/Graph.cpp BFSController.cpp BFSService.cpp ../Common/BFSRequest.cpp ../Common/BFSResult.cpp ../Common/utils.cpp ../Common/KeyboardInterruptHandler.cpp)
target_link_libraries(BFSService PUBLIC cpprestsdk::cpprest ssl crypto)