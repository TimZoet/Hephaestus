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
    class HEPHAESTUS_GUI_API WidgetMaterial final : public sol::ForwardMaterial
    {
    public:
        WidgetMaterial() = default;

        WidgetMaterial(sol::VulkanShaderModuleSharedPtr vertexModule, sol::VulkanShaderModuleSharedPtr fragmentModule);

        WidgetMaterial(const WidgetMaterial&) = delete;

        WidgetMaterial(WidgetMaterial&&) = delete;

        ~WidgetMaterial() noexcept override;

        WidgetMaterial& operator=(const WidgetMaterial&) = delete;

        WidgetMaterial& operator=(WidgetMaterial&&) = delete;
    };
}  // namespace hph