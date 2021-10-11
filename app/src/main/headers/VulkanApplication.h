#ifndef VULKAN_APPLICATION_H
#define VULKAN_APPLICATION_H

#include <vulkan/vulkan.h>
#include <android_native_app_glue.h>

class VulkanApplication
{
public:
    void run(struct android_app *app);
    void initWindow(struct android_app *app);

private:
    void initVulkan();
    void mainLoop();
    void cleanup();

    void createInstance();

    struct android_app *app;
    VkInstance instance;
};

#endif // VULKAN_APPLICATION_H