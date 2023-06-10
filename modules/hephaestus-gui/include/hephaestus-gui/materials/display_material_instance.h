#pragma once

////////////////////////////////////////////////////////////////
// Module includes.
////////////////////////////////////////////////////////////////

#include "sol/material/forward/forward_material_instance.h"
#include "sol/texture/texture2d.h"

////////////////////////////////////////////////////////////////
// Current target includes.
////////////////////////////////////////////////////////////////

#include "hephaestus-gui/dllexport.h"

namespace hph
{
    class HEPHAESTUS_GUI_API DisplayMaterialInstance final : public sol::ForwardMaterialInstance
    {
    public:
        DisplayMaterialInstance() = default;

        explicit DisplayMaterialInstance(sol::Texture2D& tex);

        DisplayMaterialInstance(const DisplayMaterialInstance&) = delete;

        DisplayMaterialInstance(DisplayMaterialInstance&&) = delete;

        ~DisplayMaterialInstance() noexcept override;

        DisplayMaterialInstance& operator=(const DisplayMaterialInstance&) = delete;

        DisplayMaterialInstance& operator=(DisplayMaterialInstance&&) = delete;

        ////////////////////////////////////////////////////////////////
        // Getters.
        ////////////////////////////////////////////////////////////////

        [[nodiscard]] uint32_t getSetIndex() const override;

        [[nodiscard]] bool isUniformBufferStale(size_t binding) const override;

        [[nodiscard]] const void* getUniformBufferData(size_t binding) const override;

        [[nodiscard]] sol::Texture2D* getTextureData(size_t binding) const override;

        ////////////////////////////////////////////////////////////////
        // Setters.
        ////////////////////////////////////////////////////////////////

        void setTexture(sol::Texture2D& tex);

    private:
        sol::Texture2D* texture = nullptr;
    };
}  // namespace hph