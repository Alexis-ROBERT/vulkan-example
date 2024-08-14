#include "common.h"
#include <iostream>

using VulkanExemple::WindowManager;
using VulkanExemple::Vulkan;    

int main(int argc, char *argv[]) 
{
    Vulkan& vulkan = Vulkan::get_instance();
    WindowManager windowManager = WindowManager(600, 600, "Vulkan Exemple");

    if(vkCreateWin32SurfaceKHR(vulkan.instance, &vulkan.infoSurfaceWin32, nullptr, &vulkan.surface) != VK_SUCCESS)
    {
        std::cerr << "Error create win 32 surface" << std::endl;

        windowManager.~WindowManager();
        return -1;
    }

    std::cout << "Success create win 32 surface" << std::endl;

    if (glfwCreateWindowSurface(vulkan.instance, windowManager.window, nullptr, &vulkan.surface) != VK_SUCCESS)
    {
        std::cerr << "Error create surface glfw for vulkan" << std::endl;

        windowManager.~WindowManager();
        return -1;
    }

    while (!glfwWindowShouldClose(windowManager.window))
    {
        glfwSwapBuffers(windowManager.window);
        glfwPollEvents();
    }

    windowManager.~WindowManager();
    return 0;
}
