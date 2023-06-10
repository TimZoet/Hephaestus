#pragma once

#ifdef HEPHAESTUS_SHARED_LIBS

#ifdef _MSC_VER
#define HEPHAESTUS_PLUGIN_LOADER_EXPORT __declspec(dllexport)
#define HEPHAESTUS_PLUGIN_LOADER_IMPORT __declspec(dllimport)
#else
#define HEPHAESTUS_PLUGIN_LOADER_EXPORT __attribute__((visibility("default")))
#define HEPHAESTUS_PLUGIN_LOADER_IMPORT
#endif

#ifdef HEPHAESTUS_EXPORT
#define HEPHAESTUS_PLUGIN_LOADER_API HEPHAESTUS_PLUGIN_LOADER_EXPORT
#else
#define HEPHAESTUS_PLUGIN_LOADER_API HEPHAESTUS_PLUGIN_LOADER_IMPORT
#endif

#else
#define HEPHAESTUS_PLUGIN_LOADER_API 
#endif