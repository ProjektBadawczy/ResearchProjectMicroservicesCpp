project(ApiGateway)
find_package(cpprestsdk REQUIRED)
add_executable(ApiGateway main.cpp ../Common/BasicController.cpp ApiController.cpp ../Common/KeyboardInterruptHandler.cpp ../Common/utils.cpp)
target_link_libraries(ApiGateway PUBLIC cpprestsdk::cpprest ssl crypto)