#include <vulkan/vulkan.h>

class VulkanApplication
{
public:
    void run();

private:
    void initVulkan();

    void mainLoop();

    void cleanup();
};