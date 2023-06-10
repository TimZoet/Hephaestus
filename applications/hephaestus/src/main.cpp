////////////////////////////////////////////////////////////////
// Standard includes.
////////////////////////////////////////////////////////////////

#include <filesystem>

////////////////////////////////////////////////////////////////
// External includes.
////////////////////////////////////////////////////////////////

#ifdef _MSC_VER
#define NOMINMAX
#include "ShlObj.h"
#endif

////////////////////////////////////////////////////////////////
// Module includes.
////////////////////////////////////////////////////////////////

#include "hephaestus-plugin-loader/plugin_loader.h"
#include "hephaestus-settings/settings.h"

////////////////////////////////////////////////////////////////
// Current target includes.
////////////////////////////////////////////////////////////////

#include "hephaestus/application.h"

int main(int, char**)
{
#if 0
    Application app;
    app.initialize();
    app.createWindow("Foo", 640, 640);
    app.createWindow("Bar", 640, 640);
    app.createCommandQueue();
    app.run();
#endif

    std::filesystem::path userDir;
#ifdef _MSC_VER
    PWSTR winUserDir;

    if (SHGetKnownFolderPath(FOLDERID_RoamingAppData, 0, nullptr, &winUserDir) != S_OK)
    {
        CoTaskMemFree(winUserDir);
        return 1;
    }
    userDir = winUserDir;
    CoTaskMemFree(winUserDir);
    userDir /= "hephaestus";
#else
#endif
    std::filesystem::create_directories(userDir);

    auto settings = std::make_unique<hph::Settings>(userDir);
    settings->load();
    hph::PluginLoader loader;
    loader.addSearchPath(std::filesystem::current_path());
    const auto plugins = loader.load();
    for (auto& plugin : plugins)
    {
        if (plugin->tryLoad())
            std::cout << "Loaded plugin " << plugin->getPath() << std::endl;
        else
            std::cout << "Failed to load plugin " << plugin->getPath() << std::endl;
    }
    return 0;
}
