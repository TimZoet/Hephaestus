#include "sample/plugin_api.h"

namespace sample
{
    ////////////////////////////////////////////////////////////////
    // Constructors.
    ////////////////////////////////////////////////////////////////

    PluginAPI::PluginAPI() = default;

    PluginAPI::~PluginAPI() noexcept = default;

    ////////////////////////////////////////////////////////////////
    // Getters.
    ////////////////////////////////////////////////////////////////

    void PluginAPI::getPluginInfo(hph::PluginInfo& info) const noexcept
    {
        info.name          = "Sample";
        info.author        = "Me";
        info.description   = "Whatever";
        info.version.major = 1;
        info.version.minor = 2;
        info.version.patch = 3;
    }

}  // namespace sample
