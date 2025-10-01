/*
 * Copyright (C) 2022 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <android/asset_manager.h>
#include <android/log.h>
#include <android/native_window.h>
#include <android/native_window_jni.h>
#include <assert.h>
#include <vulkan/vulkan.h>

#include <array>
#include <fstream>
#include <map>
#include <optional>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

/**
 * Please refer to: https://vulkan-tutorial.com/ for a gentle Vulkan
 * introduction.
 */

struct QueueFamilyIndices {
    std::optional<uint32_t> graphicsFamily;
    std::optional<uint32_t> presentFamily;
    bool isComplete() {
        return graphicsFamily.has_value() && presentFamily.has_value();
    }
};

struct SwapChainSupportDetails {
    VkSurfaceCapabilitiesKHR capabilities;
    std::vector<VkSurfaceFormatKHR> formats;
    std::vector<VkPresentModeKHR> presentModes;
};

struct ANativeWindowDeleter {
    void operator()(ANativeWindow *window) { ANativeWindow_release(window); }
};

struct UniformBufferObject {
    glm::mat4 mvp;
};

namespace vkt {
#define LOG_TAG "vkjni"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define VK_CHECK(x)                           \
  do {                                        \
    VkResult err = x;                         \
    if (err) {                                \
      LOGE("Detected Vulkan error: %d", err); \
      abort();                                \
    }                                         \
  } while (0)

class VKBasic {
 public:
    VKBasic();

    void initVulkan();
    std::vector<const char*> getRequiredExtensions(bool enableValidationLayers);
    void createInstance();
    bool checkValidationLayerSupport();
    void createSurface();
    void pickPhysicalDevice();
    bool isDeviceSuitable(VkPhysicalDevice device);
    bool checkDeviceExtensionSupport(VkPhysicalDevice device);
    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
    void createLogicalDeviceAndQueue();
    void setupDebugMessenger();
    void establishDisplaySizeIdentity();
    void createSyncObjects();
    void createSwapChain();
    SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
    void reset(ANativeWindow *newWindow, AAssetManager *newManager);
    void recreateSwapChain();
    void createImageViews();
    void createRenderPass();
    void createFramebuffers();
    void createDescriptorSetLayout();
    VkShaderModule createShaderModule(const std::vector<uint8_t> &code);
    void createGraphicsPipeline();
    void createDescriptorPool();
    void createDescriptorSets();
    void createUniformBuffers();
    void createBuffer(VkDeviceSize size, VkBufferUsageFlags usage,
                      VkMemoryPropertyFlags properties, VkBuffer &buffer,
                      VkDeviceMemory &bufferMemory);
    uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);
    void createCommandPool();
    void createCommandBuffer();
    void recordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);
    void updateUniformBuffer(uint32_t currentImage);
    void render();
    void onOrientationChange();
    void cleanupSwapChain();
    void cleanup();

    void decodeImage();
    void createTextureImage();
    void copyBufferToImage();
    void createTextureImageViews();
    void createTextureSampler();

    bool initialized() const {
        return initialized_;
    }

private:
    bool enableValidationLayers_;
    VkInstance instance_;
    VkDebugUtilsMessengerEXT debugMessenger_;
    VkSurfaceKHR surface_;
    VkPhysicalDevice physicalDevice_;
    VkDevice device_;
    VkQueue graphicsQueue_;
    VkQueue presentQueue_;
    std::unique_ptr<ANativeWindow, ANativeWindowDeleter> window_;

    AAssetManager* assetManager_;

    VkSwapchainKHR swapChain_;
    std::vector<VkImage> swapChainImages_;
    VkFormat swapChainImageFormat_;
    VkExtent2D swapChainExtent_;
    VkExtent2D displaySizeIdentity_;
    std::vector<VkImageView> swapChainImageViews_;
    std::vector<VkFramebuffer> swapChainFramebuffers_;
    VkSurfaceTransformFlagBitsKHR pretransformFlag_;

    VkRenderPass renderPass_;
    VkDescriptorSetLayout descriptorSetLayout_;
    VkPipelineLayout pipelineLayout_;
    VkPipeline graphicsPipeline_;

    VkDescriptorPool descriptorPool_;
    std::vector<VkDescriptorSet> descriptorSets_;
    std::vector<VkBuffer> uniformBuffers_;
    std::vector<VkDeviceMemory> uniformBuffersMemory_;

    VkCommandPool commandPool_;
    std::vector<VkCommandBuffer> commandBuffers_;

    std::vector<VkSemaphore> imageAvailableSemaphores_;
    std::vector<VkSemaphore> renderFinishedSemaphores_;
    std::vector<VkFence> inFlightFences_;

    bool initialized_;
    uint32_t currentFrame_;
    bool orientationChanged_;

    // texture
    int textureWidth_, textureHeight_, textureChannels_;
    VkBuffer stagingBuffer_;
    VkDeviceMemory stagingMemory_;
    VkImage textureImage_;
    VkDeviceMemory textureImageMemory_;
    VkImageView textureImageView_;
    VkSampler textureSampler_;
};

void getPrerotationMatrix(const VkSurfaceCapabilitiesKHR &capabilities,
                          const VkSurfaceTransformFlagBitsKHR &pretransformFlag,
                          glm::mat4 &mat, float ratio);

std::vector<uint8_t> LoadBinaryFileToVector(const char *file_path, AAssetManager *assetManager);

}  // namespace vkt