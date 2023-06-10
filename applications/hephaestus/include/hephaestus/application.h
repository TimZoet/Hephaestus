#pragma once

////////////////////////////////////////////////////////////////
// Standard includes.
////////////////////////////////////////////////////////////////

#include <vector>

////////////////////////////////////////////////////////////////
// Module includes.
////////////////////////////////////////////////////////////////

#include "floah-viz/font_map.h"
#include "luna/fwd.h"
#include "luna/command/fwd.h"
#include "luna/shader_cache/fwd.h"
#include "sol/core/fwd.h"
#include "sol/material/fwd.h"
#include "sol/memory/fwd.h"
#include "sol/mesh/fwd.h"
#include "sol/texture/fwd.h"

////////////////////////////////////////////////////////////////
// Current target includes.
////////////////////////////////////////////////////////////////

#include "hephaestus/window.h"

class Application
{
public:
    friend class Window;
    // TODO: Cannot set this to >1. Meshes are shared between
    // frames, so deallocating a mesh requires waiting maxFrames frames...
    // which is not supported yet. Where should this be implemented?
    // Some sort of countdown in the MeshManager, in Floah, or in user code?
    static constexpr uint32_t maxFrames = 1;

    ////////////////////////////////////////////////////////////////
    // Constructors.
    ////////////////////////////////////////////////////////////////

    Application();

    Application(const Application&) = delete;

    Application(Application&&) noexcept = delete;

    ~Application() noexcept;

    Application& operator=(const Application&) = delete;

    Application& operator=(Application&&) noexcept = delete;

    ////////////////////////////////////////////////////////////////
    // ...
    ////////////////////////////////////////////////////////////////

    Window& createWindow(std::string name, int32_t width, int32_t height);

    ////////////////////////////////////////////////////////////////
    // Init.
    ////////////////////////////////////////////////////////////////

    void initialize();

    void createCommandQueue();

    void run();

private:
    void createInstance();

    void createPhysicalDevice();

    void createDevice();

    void createManagers();

    void createCommandPool();

    void createMeshLayouts();

    void createShaderCache();

    void createMaterials();

    ////////////////////////////////////////////////////////////////
    // Member variables.
    ////////////////////////////////////////////////////////////////

    sol::VulkanInstancePtr instance;

    sol::VulkanPhysicalDevicePtr physicalDevice;

    sol::VulkanDevicePtr device;

    sol::VulkanCommandPoolPtr commandPool;

    sol::MemoryManagerPtr memoryManager;

    sol::TextureManagerPtr textureManager;

    sol::ForwardMaterialManagerPtr materialManager;

    sol::MeshManagerPtr meshManager;

    sol::MeshLayout* meshLayout = nullptr;

    sol::MeshLayout* displayMeshLayout = nullptr;

    sol::ShaderCachePtr shaderCache;

    struct
    {
        std::unique_ptr<floah::FontMap> fontmap;
        sol::VulkanShaderModuleSharedPtr widgetVertShader;
        sol::VulkanShaderModuleSharedPtr widgetFragShader;
        sol::VulkanShaderModuleSharedPtr textVertShader;
        sol::VulkanShaderModuleSharedPtr textFragShader;
    } materials;

    sol::CommandQueuePtr commandQueue;

    std::vector<std::unique_ptr<Window>> windows;

    uint32_t frameIdx = 0;

    sol::IMesh* quadMesh = nullptr;
};
