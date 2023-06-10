#pragma once

////////////////////////////////////////////////////////////////
// Module includes.
////////////////////////////////////////////////////////////////

#include "hephaestus-plugin-api/plugin_api.h"

////////////////////////////////////////////////////////////////
// Current target includes.
////////////////////////////////////////////////////////////////

#include "sample/dllexport.h"

namespace sample
{
    class HEPHAESTUS_SAMPLE_API PluginAPI final : public hph::PluginAPI
    {
    public:
        ////////////////////////////////////////////////////////////////
        // Constructors.
        ////////////////////////////////////////////////////////////////

        PluginAPI();

        PluginAPI(const PluginAPI&) = default;

        PluginAPI(PluginAPI&&) noexcept = default;

        ~PluginAPI() noexcept override;

        PluginAPI& operator=(const PluginAPI&) = default;

        PluginAPI& operator=(PluginAPI&&) noexcept = default;

        ////////////////////////////////////////////////////////////////
        // Getters.
        ////////////////////////////////////////////////////////////////

        void getPluginInfo(hph::PluginInfo& info) const noexcept override;
    };

    inline hph::PluginAPI* create()
    {
        static PluginAPI api;
        return &api;
    }
}  // namespace sample

HEPHAESTUS_DLL(sample::create)
