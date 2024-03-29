#pragma once

////////////////////////////////////////////////////////////////
// Standard includes.
////////////////////////////////////////////////////////////////

#include <filesystem>
#include <string>
#include <vector>

////////////////////////////////////////////////////////////////
// Current target includes.
////////////////////////////////////////////////////////////////

#include "hephaestus-settings/dllexport.h"

namespace hph
{
    class HEPHAESTUS_SETTINGS_API Settings final
    {
    public:
        ////////////////////////////////////////////////////////////////
        // Constructors.
        ////////////////////////////////////////////////////////////////

        Settings() = default;

        Settings(std::filesystem::path dir);

        Settings(const Settings&) = delete;

        Settings(Settings&&) noexcept = default;

        ~Settings() noexcept = default;

        Settings& operator=(const Settings&) = delete;

        Settings& operator=(Settings&&) noexcept = default;

        ////////////////////////////////////////////////////////////////
        // Getters.
        ////////////////////////////////////////////////////////////////

        [[nodiscard]] std::vector<std::string>& getPluginSearchPaths() noexcept;

        [[nodiscard]] const std::vector<std::string>& getPluginSearchPaths() const noexcept;

        ////////////////////////////////////////////////////////////////
        // Setters.
        ////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////
        // Loading/Saving.
        ////////////////////////////////////////////////////////////////

        void load();

        void save() const;

    private:
        ////////////////////////////////////////////////////////////////
        // Member variables.
        ////////////////////////////////////////////////////////////////

        /**
         * \brief Path to directory in which the settings file is saved.
         */
        std::filesystem::path directory;

        /**
         * \brief List of directories to be searched for plugins.
         */
        std::vector<std::string> pluginSearchPaths;
    };
}  // namespace hph
