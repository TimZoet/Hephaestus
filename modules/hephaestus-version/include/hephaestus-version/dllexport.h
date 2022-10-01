#pragma once

#if defined(_MSC_VER)
#define HEPHAESTUS_GUI_EXPORT __declspec(dllexport)
#define HEPHAESTUS_GUI_IMPORT __declspec(dllimport)
#else
#define HEPHAESTUS_GUI_EXPORT __attribute__((visibility("default")))
#define HEPHAESTUS_GUI_IMPORT
#endif

#ifdef HEPHAESTUS_EXPORT
#define HEPHAESTUS_GUI HEPHAESTUS_GUI_EXPORT
#else
#define HEPHAESTUS_GUI HEPHAESTUS_GUI_IMPORT
#endif
