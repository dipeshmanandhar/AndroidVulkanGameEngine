#include "VulkanApplication.h"

#include <stdexcept>
#include <type_traits>

#include "Logging.h"

void VulkanApplication::run(struct android_app *app)
{
    try
    {
        initWindow(app);
        initVulkan();
        mainLoop();
        cleanup();
    }
    catch (const std::exception &e)
    {
        LOGE("%s", e.what());
    }
}

void VulkanApplication::initWindow(struct android_app *app)
{
    LOGI("Initializing window");
    
    this->app = app;
}

void VulkanApplication::initVulkan()
{
    LOGI("Initializing Vulkan");

    createInstance();
}

void VulkanApplication::mainLoop()
{
    LOGI("Start of Vulkan Main Loop");

    while (app->destroyRequested == 0)
    {
    }
}

void VulkanApplication::cleanup()
{
    LOGI("Clean up Vulkan");

    vkDestroyInstance(instance, nullptr);
}

void VulkanApplication::createInstance()
{
    LOGI("Creating Instance");

    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "AndroidVulkanGameEngine";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    const char *instance_extensions[] = {
        "VK_KHR_surface",
        "VK_KHR_android_surface"
    };

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;
    createInfo.enabledExtensionCount = std::extent<decltype(instance_extensions)>::value;
    createInfo.ppEnabledExtensionNames = instance_extensions;
    createInfo.enabledLayerCount = 0;

    if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS)
    {
        throw std::runtime_error("Failed to create instance!");
    }
}