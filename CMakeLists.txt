cmake_minimum_required(VERSION 3.10.0)
project(boost_asio_demo VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

# Find Boost
find_package(Boost REQUIRED COMPONENTS system)

# Include directories
include_directories(${Boost_INCLUDE_DIRS})

add_executable(server server.cpp)
target_link_libraries(server PRIVATE ${Boost_LIBRARIES} pthread)

add_executable(client client.cpp)
target_link_libraries(client PRIVATE ${Boost_LIBRARIES} pthread)


