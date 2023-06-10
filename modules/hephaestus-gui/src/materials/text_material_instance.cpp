#include "hephaestus-gui/materials/text_material_instance.h"

////////////////////////////////////////////////////////////////
// Module includes.
////////////////////////////////////////////////////////////////

#include "sol/material/forward/forward_material_manager.h"

namespace hph
{
    TextMaterialInstance::TextMaterialInstance(sol::Texture2D& fmap) : fontmap(&fmap) {}

    TextMaterialInstance::~TextMaterialInstance() noexcept = default;

    uint32_t TextMaterialInstance::getSetIndex() const { return fontmap ? 1 : 0; }

    bool TextMaterialInstance::isUniformBufferStale(size_t) const { return false; }

    const void* TextMaterialInstance::getUniformBufferData(size_t) const { return &windowTransform; }

    sol::Texture2D* TextMaterialInstance::getTextureData(size_t) const { return fontmap; }

    ////////////////////////////////////////////////////////////////
    // Setters.
    ////////////////////////////////////////////////////////////////

    void TextMaterialInstance::setFontmap(sol::Texture2D& fmap) { fontmap = &fmap; }

    void TextMaterialInstance::setWindowTransform(math::float4 lower, math::float4 upper)
    {
        windowTransform.r0 = std::move(lower);
        windowTransform.r1 = std::move(upper);
    }
}  // namespace hph