#pragma once

////////////////////////////////////////////////////////////////
// Standard includes.
////////////////////////////////////////////////////////////////

#include <string>

namespace hph
{
    struct PluginVersion
    {
        uint32_t major = 0;

        uint32_t minor = 0;

        uint32_t patch = 0;
    };

    struct PluginInfo
    {
        std::string name;

        std::string author;

        std::string description;

        PluginVersion version;
    };
}  // namespace hph
