#ifndef VULKAN_APPLICATION_H
#define VULKAN_APPLICATION_H

#include <vulkan/vulkan.h>
#include <android_native_app_glue.h>

#include <vector>

class VulkanApplication
{
public:
    void run(struct android_app *app);
    void initWindow(struct android_app *app);

private:
    void initVulkan();
    void mainLoop();
    void cleanup();

    // initVulkan helpers
    void createInstance();
    bool checkValidationLayerSupport();
    std::vector<const char *> getRequiredExtensions();
    static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
        VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
        VkDebugUtilsMessageTypeFlagsEXT messageType,
        const VkDebugUtilsMessengerCallbackDataEXT *pCallbackData,
        void *pUserData);
    void setupDebugMessenger();
    void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT &createInfo);

    // extension functions
    static VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkDebugUtilsMessengerEXT *pDebugMessenger);
    static void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks *pAllocator);

    // member fields
    struct android_app *app;
    VkInstance instance;
    VkDebugUtilsMessengerEXT debugMessenger;
};

#endif // VULKAN_APPLICATION_H