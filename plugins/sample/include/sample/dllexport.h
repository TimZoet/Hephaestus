#pragma once

#ifdef _MSC_VER
#define HEPHAESTUS_SAMPLE_EXPORT __declspec(dllexport)
#define HEPHAESTUS_SAMPLE_IMPORT __declspec(dllimport)
#else
#define HEPHAESTUS_SAMPLE_EXPORT __attribute__((visibility("default")))
#define HEPHAESTUS_SAMPLE_IMPORT
#endif

#ifdef HEPHAESTUS_EXPORT
#define HEPHAESTUS_SAMPLE_API HEPHAESTUS_SAMPLE_EXPORT
#else
#define HEPHAESTUS_SAMPLE_API HEPHAESTUS_SAMPLE_IMPORT
#endif
