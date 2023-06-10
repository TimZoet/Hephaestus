#include "hephaestus-gui/materials/display_material_instance.h"

////////////////////////////////////////////////////////////////
// Module includes.
////////////////////////////////////////////////////////////////

#include "sol/material/forward/forward_material_manager.h"

namespace hph
{
    DisplayMaterialInstance::DisplayMaterialInstance(sol::Texture2D& tex) : texture(&tex) {}

    DisplayMaterialInstance::~DisplayMaterialInstance() noexcept = default;

    uint32_t DisplayMaterialInstance::getSetIndex() const { return 0; }

    bool DisplayMaterialInstance::isUniformBufferStale(size_t) const { return false; }

    const void* DisplayMaterialInstance::getUniformBufferData(size_t) const { return nullptr; }

    sol::Texture2D* DisplayMaterialInstance::getTextureData(size_t) const { return texture; }

    void DisplayMaterialInstance::setTexture(sol::Texture2D& tex) { texture = &tex; }
}  // namespace hph