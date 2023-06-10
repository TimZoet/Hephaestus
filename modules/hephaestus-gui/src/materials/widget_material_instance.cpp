#include "hephaestus-gui/materials/widget_material_instance.h"

////////////////////////////////////////////////////////////////
// Module includes.
////////////////////////////////////////////////////////////////

#include "sol/material/forward/forward_material_manager.h"
#include "sol/texture/texture_manager.h"

namespace hph
{
    WidgetMaterialInstance::~WidgetMaterialInstance() noexcept = default;

    ////////////////////////////////////////////////////////////////
    // Getters.
    ////////////////////////////////////////////////////////////////

    uint32_t WidgetMaterialInstance::getSetIndex() const { return 0; }

    bool WidgetMaterialInstance::isUniformBufferStale(size_t) const { return false; }

    const void* WidgetMaterialInstance::getUniformBufferData(size_t) const { return &windowTransform; }

    sol::Texture2D* WidgetMaterialInstance::getTextureData(size_t) const { return nullptr; }

    ////////////////////////////////////////////////////////////////
    // Setters.
    ////////////////////////////////////////////////////////////////

    void WidgetMaterialInstance::setWindowTransform(math::float4 lower, math::float4 upper)
    {
        windowTransform.r0 = std::move(lower);
        windowTransform.r1 = std::move(upper);
    }
}  // namespace hph