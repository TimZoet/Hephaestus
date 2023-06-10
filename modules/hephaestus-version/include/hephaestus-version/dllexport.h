#pragma once

#ifdef HEPHAESTUS_SHARED_LIBS

#ifdef _MSC_VER
#define HEPHAESTUS_VERSION_EXPORT __declspec(dllexport)
#define HEPHAESTUS_VERSION_IMPORT __declspec(dllimport)
#else
#define HEPHAESTUS_VERSION_EXPORT __attribute__((visibility("default")))
#define HEPHAESTUS_VERSION_IMPORT
#endif

#ifdef HEPHAESTUS_EXPORT
#define HEPHAESTUS_VERSION_API HEPHAESTUS_VERSION_EXPORT
#else
#define HEPHAESTUS_VERSION_API HEPHAESTUS_VERSION_IMPORT
#endif

#else
#define HEPHAESTUS_VERSION_API
#endif