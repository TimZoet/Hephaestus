#pragma once

#ifdef HEPHAESTUS_SHARED_LIBS

#ifdef _MSC_VER
#define HEPHAESTUS_SETTINGS_EXPORT __declspec(dllexport)
#define HEPHAESTUS_SETTINGS_IMPORT __declspec(dllimport)
#else
#define HEPHAESTUS_SETTINGS_EXPORT __attribute__((visibility("default")))
#define HEPHAESTUS_SETTINGS_IMPORT
#endif

#ifdef HEPHAESTUS_EXPORT
#define HEPHAESTUS_SETTINGS_API HEPHAESTUS_SETTINGS_EXPORT
#else
#define HEPHAESTUS_SETTINGS_API HEPHAESTUS_SETTINGS_IMPORT
#endif

#else
#define HEPHAESTUS_SETTINGS_API 
#endif