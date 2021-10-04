cmake_minimum_required(VERSION 3.12)

# set project name
project(AndroidVulkanGameEngine)

# build native_app_glue as a static lib
set(${CMAKE_C_FLAGS}, "${CMAKE_C_FLAGS}")
set(NATIVE_APP_GLUE_DIR ${ANDROID_NDK}/sources/android/native_app_glue)
# include_directories(${NATIVE_APP_GLUE_DIR})
add_library(native_app_glue STATIC
    ${NATIVE_APP_GLUE_DIR}/android_native_app_glue.c)

# now build app's shared lib
set(SRC_DIR src/main/cpp)
set(INC_DIR src/main/headers)
file(GLOB SRC_FILES CONFIGURE_DEPENDS "${SRC_DIR}/*.cpp")
# file(GLOB INC_FILES CONFIGURE_DEPENDS "${INC_DIR}/*.h")
set(VULKAN_DIR $ENV{VULKAN_SDK}/Include/)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror")

# Export ANativeActivity_onCreate(),
# Refer to: https://github.com/android-ndk/ndk/issues/381.
set(CMAKE_SHARED_LINKER_FLAGS
    "${CMAKE_SHARED_LINKER_FLAGS} -u ANativeActivity_onCreate")

add_library(AndroidVulkanGameEngine SHARED
            ${SRC_FILES})

target_include_directories(AndroidVulkanGameEngine PRIVATE
    ${NATIVE_APP_GLUE_DIR}
    ${INC_DIR}
    ${VULKAN_DIR})

# add lib dependencies
target_link_libraries(
    AndroidVulkanGameEngine
    android
    native_app_glue
    log)