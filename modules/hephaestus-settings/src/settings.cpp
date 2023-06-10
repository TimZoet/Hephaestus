#include "hephaestus-settings/settings.h"

////////////////////////////////////////////////////////////////
// Module includes.
////////////////////////////////////////////////////////////////

#include "alexandria/library.h"

namespace
{
    struct PluginSettings
    {
        static constexpr auto typeName = "PluginSettings";

        alex::InstanceId  id;
        alex::StringArray searchPaths;
    };

    using PluginSettingsHandler =
      alex::object_handler_t<alex::Member<&PluginSettings::id>, alex::Member<&PluginSettings::searchPaths>>;

    void createSettingsTypes(alex::Library& lib)
    {
        auto& pluginSettings = lib.createType(PluginSettings::typeName);
        pluginSettings.createStringArrayProperty("search_paths");
        lib.commitType(pluginSettings);
    }
}  // namespace

namespace hph
{
    ////////////////////////////////////////////////////////////////
    // Constructors.
    ////////////////////////////////////////////////////////////////

    Settings::Settings(std::filesystem::path dir) : directory(std::move(dir)) {}

    ////////////////////////////////////////////////////////////////
    // Getters.
    ////////////////////////////////////////////////////////////////

    std::vector<std::string>& Settings::getPluginSearchPaths() noexcept { return pluginSearchPaths; }

    const std::vector<std::string>& Settings::getPluginSearchPaths() const noexcept { return pluginSearchPaths; }

    ////////////////////////////////////////////////////////////////
    // Loading/Saving.
    ////////////////////////////////////////////////////////////////

    void Settings::load()
    {
        auto [lib, created] = alex::Library::openOrCreate(directory / "settings.db");

        if (created) { createSettingsTypes(*lib); }
        else
        {
            const auto     handler = lib->createObjectHandler<PluginSettingsHandler>(PluginSettings::typeName);
            PluginSettings pluginSettings;
            handler->get(handler->list().front(), pluginSettings);
            pluginSearchPaths = std::move(pluginSettings.searchPaths.get());
        }
    }

    void Settings::save() const
    {
        // For now we just remove the old file to be able to dump all data.
        // In the future appending/modifying would be better.
        std::filesystem::remove(directory / "settings.db");
        const auto lib = alex::Library::create(directory / "settings.db");
        createSettingsTypes(*lib);

        {
            const auto     handler = lib->createObjectHandler<PluginSettingsHandler>(PluginSettings::typeName);
            PluginSettings pluginSettings;
            pluginSettings.searchPaths.get() = pluginSearchPaths;
            handler->insert(pluginSettings);
        }
    }
}  // namespace hph
