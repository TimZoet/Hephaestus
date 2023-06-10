#pragma once

////////////////////////////////////////////////////////////////
// External includes.
////////////////////////////////////////////////////////////////

#include "boost/config.hpp"
#include "boost/dll.hpp"

////////////////////////////////////////////////////////////////
// Current target includes.
////////////////////////////////////////////////////////////////

#include "hephaestus-plugin-api/dllexport.h"
#include "hephaestus-plugin-api/plugin_info.h"

namespace hph
{
    class HEPHAESTUS_PLUGIN_API_API PluginAPI
    {
    public:
        ////////////////////////////////////////////////////////////////
        // Constructors.
        ////////////////////////////////////////////////////////////////

        PluginAPI() = default;

        PluginAPI(const PluginAPI&) = default;

        PluginAPI(PluginAPI&&) noexcept = default;

        virtual ~PluginAPI() noexcept = default;

        PluginAPI& operator=(const PluginAPI&) = default;

        PluginAPI& operator=(PluginAPI&&) noexcept = default;

        ////////////////////////////////////////////////////////////////
        // Getters.
        ////////////////////////////////////////////////////////////////

        /**
         * \brief Get the information describing this plugin.
         * \param info PluginInfo struct to fill.
         */
        virtual void getPluginInfo(PluginInfo& info) const noexcept = 0;
    };
}  // namespace hph

/**
 * \brief Makes the function that is responsible for initializing this plugin available.
 * Each plugin should contain exactly one usage of this macro.
 * \param func Function with the signature hph::PluginAPI*(void).
 */
#define HEPHAESTUS_DLL(func) BOOST_DLL_ALIAS_SECTIONED(func, hph_create_plugin, hph)
