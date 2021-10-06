#include <android/log.h>
#include <android_native_app_glue.h>

#include "Logging.h"
#include "VulkanApplication.h"

// Process the next main command.
void handle_cmd(struct android_app *app, int32_t cmd)
{
    switch (cmd)
    {
    case APP_CMD_INIT_WINDOW:
        // The window is being shown, get it ready.
        LOGI("Initializing window...");
        break;
    case APP_CMD_TERM_WINDOW:
        // The window is being hidden or closed, clean it up.
        LOGI("Terminating window...");
        break;
    default:
        LOGI("Event not handled: %d", cmd);
    }
}

/**
 * This is the main entry point of a native application that is using
 * android_native_app_glue.  It runs in its own thread, with its own
 * event loop for receiving input events and doing other things.
 */
void android_main(struct android_app *app)
{
    LOGI("Start of android_main");

    // Set the callback to process system events
    app->onAppCmd = handle_cmd;

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

    LOGI("End of android_main");
}