cmake_minimum_required(VERSION 3.28)

project(vulkan_exemple)

set(CXX_STANDARD_REQUIRED 20)

include_directories(
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/ext/header
)

link_directories(${CMAKE_SOURCE_DIR}/ext/lib)

add_subdirectory(src)