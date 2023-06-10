#pragma once

////////////////////////////////////////////////////////////////
// Module includes.
////////////////////////////////////////////////////////////////

#include "sol/core/fwd.h"
#include "sol/material/forward/forward_material.h"

////////////////////////////////////////////////////////////////
// Current target includes.
////////////////////////////////////////////////////////////////

#include "hephaestus-gui/dllexport.h"

namespace hph
{
    class HEPHAESTUS_GUI_API DisplayMaterial final : public sol::ForwardMaterial
    {
    public:
        DisplayMaterial() = default;

        DisplayMaterial(sol::VulkanShaderModuleSharedPtr vertexModule, sol::VulkanShaderModuleSharedPtr fragmentModule);

        DisplayMaterial(const DisplayMaterial&) = delete;

        DisplayMaterial(DisplayMaterial&&) = delete;

        ~DisplayMaterial() noexcept override;

        DisplayMaterial& operator=(const DisplayMaterial&) = delete;

        DisplayMaterial& operator=(DisplayMaterial&&) = delete;
    };
}  // namespace hph