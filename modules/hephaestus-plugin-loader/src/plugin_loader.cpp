#include "hephaestus-plugin-loader/plugin_loader.h"

////////////////////////////////////////////////////////////////
// External includes.
////////////////////////////////////////////////////////////////

#include "boost/dll.hpp"

namespace hph
{
    ////////////////////////////////////////////////////////////////
    // Loading.
    ////////////////////////////////////////////////////////////////

    void PluginLoader::addSearchPath(std::filesystem::path path) { searchPaths.push_back(std::move(path)); }

    std::vector<std::unique_ptr<Plugin>> PluginLoader::load() const
    {
        std::vector<std::unique_ptr<Plugin>> plugins;

        for (const auto& dir : searchPaths)
        {
            for (const auto& file : std::filesystem::directory_iterator{dir})
            {
#ifdef _MSC_VER
                if (file.path().extension() != ".dll") continue;
#else
                if (file.path().extension() != ".so") continue;
#endif

                for (boost::dll::library_info inf(file.path().c_str()); const auto& symbol : inf.symbols("hph"))
                {
                    if (symbol == "hph_create_plugin")
                    {
                        plugins.emplace_back(std::make_unique<Plugin>(file));
                        break;
                    }
                }
            }
        }

        return plugins;
    }
}  // namespace hph
