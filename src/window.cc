#include "common.h"
#include <iostream>

namespace VulkanExemple
{
    WindowManager::WindowManager(int width, int height, const char* title)
    {
        if (!glfwInit())
        {
            throw std::runtime_error("Error glfw init");
        }

        std::cout << "Success glfw init" << std::endl;

        window = glfwCreateWindow(width, height, title, nullptr, nullptr);

        if (!window) {
            glfwDestroyWindow(window);
        }
    }

    WindowManager::~WindowManager() {
        glfwDestroyWindow(window);
    }
}