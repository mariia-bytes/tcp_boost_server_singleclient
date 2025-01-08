cmake_minimum_required(VERSION 3.10)

# Project name
project(tcpBoostASIO_server_SingleClient)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)Help people interested in this repository understand your project by adding a README.
Add a README
About
No description, website, or topics provided.
 Activity
Stars
 0 stars
Watchers
 1 watching
Forks
 0 forks
Releases
No releases published
Create a new release
Packages
No packages published
Publish your first package
Languages
Makefile
85.0%
 
C++
6.2%
 
C
5.5%
 
CMake
3.3%
Suggested workflows
Based on your tech stack
￼
CMake based, single-platform projects
Configure CMake based, single-platform projects
Build and test a CMake based project on a single-platform.
￼
C/C++ with Make
Configure C/C++ with Make
Build and test a C/C++ project using Make.
￼
CMake based, multi-platform projects
Configure CMake based, multi-platform projects
Build and test a CMake based project on multiple platforms.
More workflows
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