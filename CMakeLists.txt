cmake_minimum_required(VERSION 3.10)

# Project name
project(tcpBoostASIO_server_SingleClient)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find Boost libraries (specify the components you need)
find_package(Boost REQUIRED COMPONENTS system)

# Include directories for Boost
include_directories(${Boost_INCLUDE_DIRS})

# Add executables for client and server
add_executable(boost_client boost_client.cpp)
add_executable(boost_server boost_server.cpp)

# Link Boost libraries to the executables
target_link_libraries(boost_client ${Boost_LIBRARIES})
target_link_libraries(boost_server ${Boost_LIBRARIES})