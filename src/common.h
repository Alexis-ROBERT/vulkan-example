#include <windows.h>

#define GLFW_INCLUDE_VULKAN
#include <glfw3.h>

#include <vulkan/vulkan.h>
#include <vulkan/vulkan_win32.h>

namespace VulkanExemple
{
    class WindowManager {
    public:
        WindowManager(int width, int height, const char* title);
        ~WindowManager();

        GLFWwindow* window;
    };

    class Vulkan {
    public:
        VkInstance instance{};
        VkApplicationInfo appinfo{};
        VkInstanceCreateInfo info{};
        VkSurfaceKHR surface{}; 
        VkWin32SurfaceCreateInfoKHR infoSurfaceWin32{};

        static Vulkan& get_instance() noexcept;

    private:
        Vulkan();
        ~Vulkan();
    };

    class VulkanDevice {
    public:
        VulkanDevice();
        ~VulkanDevice();

        void searchDevice();

        VkDevice device{};
    };
}