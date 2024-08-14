file(GLOB_RECURSE S_FILES *.cc *.cpp)
file(GLOB_RECURSE H_FILES *.hh *.hpp)

find_package(Vulkan REQUIRED)

include_directories(${Vulkan_INCLUDE_DIRS})

add_executable(vulkan_exemple ${S_FILES} ${H_FILES})
target_link_libraries(vulkan_exemple PRIVATE glfw3 ${Vulkan_LIBRARIES})