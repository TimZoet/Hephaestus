#pragma once

#ifdef _MSC_VER
#define HEPHAESTUS_PLUGIN_API_EXPORT __declspec(dllexport)
#define HEPHAESTUS_PLUGIN_API_IMPORT __declspec(dllimport)
#else
#define HEPHAESTUS_PLUGIN_API_EXPORT __attribute__((visibility("default")))
#define HEPHAESTUS_PLUGIN_API_IMPORT
#endif

#ifdef HEPHAESTUS_EXPORT
#define HEPHAESTUS_PLUGIN_API_API HEPHAESTUS_PLUGIN_API_EXPORT
#else
#define HEPHAESTUS_PLUGIN_API_API HEPHAESTUS_PLUGIN_API_IMPORT
#endif
