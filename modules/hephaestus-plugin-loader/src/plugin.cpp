#include "hephaestus-plugin-loader/plugin.h"

#include "boost/dll.hpp"

namespace hph
{
    ////////////////////////////////////////////////////////////////
    // Constructors.
    ////////////////////////////////////////////////////////////////

    Plugin::Plugin(std::filesystem::path libPath) : path(std::move(libPath)) {}

    Plugin::~Plugin() noexcept = default;

    ////////////////////////////////////////////////////////////////
    // Getters.
    ////////////////////////////////////////////////////////////////

    const std::filesystem::path& Plugin::getPath() const noexcept { return path; }

    bool Plugin::isLoaded() const noexcept { return api; }

    ////////////////////////////////////////////////////////////////
    // Loading.
    ////////////////////////////////////////////////////////////////

    bool Plugin::tryLoad()
    {
        // TODO: Inform of reason for failure.

        if (api) return true;
        if (!exists(path)) return false;

        // Try to load library.
        try
        {
            library = std::make_unique<boost::dll::shared_library>(path.c_str());
        }
        catch (const std::exception&)
        {
            return false;
        }

        // Try to retrieve and call create function.
        try
        {
            api = library->get_alias<PluginAPI*()>("hph_create_plugin")();
        }
        catch (const std::exception&)
        {
            return false;
        }

        return true;
    }

}  // namespace hph
