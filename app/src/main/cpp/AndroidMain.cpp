#include <android/log.h>
#include <android_native_app_glue.h>

#include "VulkanApplication.h"

/**
 * This is the main entry point of a native application that is using
 * android_native_app_glue.  It runs in its own thread, with its own
 * event loop for receiving input events and doing other things.
 */
void android_main(struct android_app *app)
{
    __android_log_print(ANDROID_LOG_INFO, "AndroidVulkanGameEngine", "Hello World!");

    VulkanApplication vulkan_app;
    vulkan_app.run();

    // Used to poll the events in the main loop
    int events;
    android_poll_source *source;

    do
    {
        // poll events
        if (ALooper_pollAll(0, nullptr, &events, (void **)&source) >= 0)
        {
            if (source != NULL)
                source->process(app, source);
        }

    } while (app->destroyRequested == 0);
}