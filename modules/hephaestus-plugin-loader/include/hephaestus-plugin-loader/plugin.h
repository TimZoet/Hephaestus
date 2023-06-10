#pragma once

////////////////////////////////////////////////////////////////
// Standard includes.
////////////////////////////////////////////////////////////////

#include <filesystem>
#include <memory>

////////////////////////////////////////////////////////////////
// External includes.
////////////////////////////////////////////////////////////////

//#include "boost/dll.hpp"

////////////////////////////////////////////////////////////////
// Module includes.
////////////////////////////////////////////////////////////////

#include "hephaestus-plugin-api/plugin_api.h"

namespace boost::dll
{
    class shared_library;
}

namespace hph
{
    class Plugin final
    {
    public:
        ////////////////////////////////////////////////////////////////
        // Constructors.
        ////////////////////////////////////////////////////////////////

        Plugin() = default;

        /**
         * \brief Construct a new Plugin. Construction will not yet load any symbols.
         * \param libPath Path to the dynamic library file.
         */
        explicit Plugin(std::filesystem::path libPath);

        Plugin(const Plugin&) = delete;

        Plugin(Plugin&&) noexcept = default;

        ~Plugin() noexcept;

        Plugin& operator=(const Plugin&) = delete;

        Plugin& operator=(Plugin&&) noexcept = default;

        ////////////////////////////////////////////////////////////////
        // Getters.
        ////////////////////////////////////////////////////////////////

        /**
         * \brief Get the path to the dynamic library file.
         * \return Path to file.
         */
        [[nodiscard]] const std::filesystem::path& getPath() const noexcept;

        /**
         * \brief Returns whether the plugin was loaded successfully.
         * \return True if loaded successfully, false otherwise.
         */
        [[nodiscard]] bool isLoaded() const noexcept;

        ////////////////////////////////////////////////////////////////
        // Loading.
        ////////////////////////////////////////////////////////////////

        /**
         * \brief Try to load symbols from the shared library and construct the PluginAPI.
         * \return True on success, false otherwise.
         */
        [[nodiscard]] bool tryLoad();

    private:
        ////////////////////////////////////////////////////////////////
        // Member variables.
        ////////////////////////////////////////////////////////////////

        std::filesystem::path path;

        std::unique_ptr<boost::dll::shared_library> library;

        PluginAPI* api = nullptr;
    };
}  // namespace hph
