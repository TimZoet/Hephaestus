#pragma once

////////////////////////////////////////////////////////////////
// Standard includes.
////////////////////////////////////////////////////////////////

#include <filesystem>
#include <vector>

////////////////////////////////////////////////////////////////
// Current target includes.
////////////////////////////////////////////////////////////////

#include "hephaestus-plugin-loader/dllexport.h"
#include "hephaestus-plugin-loader/plugin.h"

namespace hph
{
    class HEPHAESTUS_PLUGIN_LOADER_API PluginLoader final
    {
    public:
        ////////////////////////////////////////////////////////////////
        // Constructors.
        ////////////////////////////////////////////////////////////////

        PluginLoader() = default;

        PluginLoader(const PluginLoader&) = delete;

        PluginLoader(PluginLoader&&) noexcept = default;

        ~PluginLoader() noexcept = default;

        PluginLoader& operator=(const PluginLoader&) = delete;

        PluginLoader& operator=(PluginLoader&&) noexcept = default;

        ////////////////////////////////////////////////////////////////
        // Loading.
        ////////////////////////////////////////////////////////////////

        /**
         * \brief Add a new directory path in which to search for plugins.
         * \param path Path to directory.
         */
        void addSearchPath(std::filesystem::path path);

        /**
         * \brief Search the added search directories for dynamic libraries that are a valid plugin.
         * Does not yet load any of the plugins.
         * \return List of plugins.
         */
        [[nodiscard]] std::vector<std::unique_ptr<Plugin>> load() const;

    private:
        ////////////////////////////////////////////////////////////////
        // Member variables.
        ////////////////////////////////////////////////////////////////

        /**
         * \brief List of directories to be searched for plugins.
         */
        std::vector<std::filesystem::path> searchPaths;
    };
}  // namespace hph
