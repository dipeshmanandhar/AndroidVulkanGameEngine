#include "VulkanApplication.h"
#include "Logging.h"

void VulkanApplication::run(struct android_app *app)
{
    initWindow(app);
    initVulkan();
    mainLoop();
    cleanup();
}

void VulkanApplication::initWindow(struct android_app *app)
{
    LOGI("Initializing window");
    this->app = app;
}

void VulkanApplication::initVulkan()
{
    LOGI("Initializing Vulkan");
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
}