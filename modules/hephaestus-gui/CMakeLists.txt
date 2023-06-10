find_package(common REQUIRED)
find_package(floah REQUIRED)

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_CURRENT_SOURCE_DIR}/../hephaestus-version")
include(hephaestusVersionString)

set(NAME hephaestus-gui)
set(TYPE module)
set(LINKING)
set(INCLUDE_DIR "include/hephaestus-gui")
set(SRC_DIR "src")

if (HEPHAESTUS_SHARED_LIBS)
    set(LINKING DYNAMIC)
endif()

set(HEADERS
    ${INCLUDE_DIR}/dllexport.h
    ${INCLUDE_DIR}/gui.h

    ${INCLUDE_DIR}/materials/display_material.h
    ${INCLUDE_DIR}/materials/display_material_instance.h
    ${INCLUDE_DIR}/materials/panel_transform_node.h
    ${INCLUDE_DIR}/materials/text_material.h
    ${INCLUDE_DIR}/materials/text_material_instance.h
    ${INCLUDE_DIR}/materials/widget_material.h
    ${INCLUDE_DIR}/materials/widget_material_instance.h
    ${INCLUDE_DIR}/materials/widget_transform_node.h
)

set(SOURCES
    ${SRC_DIR}/gui.cpp

    ${SRC_DIR}/materials/display_material.cpp
    ${SRC_DIR}/materials/display_material_instance.cpp
    ${SRC_DIR}/materials/panel_transform_node.cpp
    ${SRC_DIR}/materials/text_material.cpp
    ${SRC_DIR}/materials/text_material_instance.cpp
    ${SRC_DIR}/materials/widget_material.cpp
    ${SRC_DIR}/materials/widget_material_instance.cpp
    ${SRC_DIR}/materials/widget_transform_node.cpp
)

set(DEPS_PUBLIC
    floah::widget
    math::math
    sol::core
)

set(DEPS_PRIVATE
    common::common
)

make_target(
    NAME ${NAME}
    TYPE ${TYPE} ${LINKING}
    VERSION ${HEPHAESTUS_VERSION}
    WARNINGS WERROR
    HEADERS "${HEADERS}"
    SOURCES "${SOURCES}"
    DEPS_PUBLIC "${DEPS_PUBLIC}"
    DEPS_PRIVATE "${DEPS_PRIVATE}"
)

install_target(
    NAME ${NAME}
    TYPE ${TYPE}
    VERSION ${HEPHAESTUS_VERSION}
    HEADERS "${HEADERS}"
)

target_compile_definitions(
    ${NAME}
    PRIVATE
        HEPHAESTUS_VERSION_MAJOR=${HEPHAESTUS_VERSION_MAJOR}
        HEPHAESTUS_VERSION_MINOR=${HEPHAESTUS_VERSION_MINOR}
        HEPHAESTUS_VERSION_PATCH=${HEPHAESTUS_VERSION_PATCH}
        HEPHAESTUS_EXPORT=1
)

if (HEPHAESTUS_SHARED_LIBS)
    target_compile_definitions(${NAME} PRIVATE HEPHAESTUS_SHARED_LIBS=1)
endif()