#include "common.h"
#include <iostream>

namespace VulkanExemple 
{

    Vulkan::Vulkan()
    {
        appinfo.sType              = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        appinfo.apiVersion         = VK_API_VERSION_1_3;
        appinfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        appinfo.engineVersion      = VK_MAKE_VERSION(1, 0, 0);
        appinfo.pApplicationName   = "Vulkan Exemple";
        appinfo.pEngineName        = "Vulkan Engine";

        info.pApplicationInfo = &appinfo;
        
        uint32_t glfw_extension_count = 0;
        const char** glfw_extension_name = glfwGetRequiredInstanceExtensions(&glfw_extension_count);

        std::cout << glfw_extension_name << std::endl;

        info.enabledExtensionCount = glfw_extension_count;
        info.ppEnabledExtensionNames = glfw_extension_name;

        info.enabledLayerCount = 0;

        const char* extensions_name[]    = {
            VK_KHR_SURFACE_EXTENSION_NAME,
            VK_KHR_WIN32_SURFACE_EXTENSION_NAME
        };

        info.enabledExtensionCount   = 2;
        info.ppEnabledExtensionNames = extensions_name;
        info.sType                   = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;

        if (vkCreateInstance(&info, nullptr, &instance) != VK_SUCCESS)
        {
            throw std::runtime_error("ERROR create instance vulkan");
        }

        std::cout << "SUCCESS create instance vulkan" << std::endl;
    }

    Vulkan::~Vulkan()
    {
        vkDestroyInstance(instance, nullptr);
    }

    Vulkan& Vulkan::get_instance() noexcept
    {
        static Vulkan instance;
        return instance;
    }
}