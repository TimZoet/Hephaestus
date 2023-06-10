find_package(boost COMPONENTS dll REQUIRED)

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_CURRENT_SOURCE_DIR}/../hephaestus-version")
include(hephaestusVersionString)

set(NAME hephaestus-plugin-loader)
set(TYPE module)
set(LINKING)
set(INCLUDE_DIR "include/hephaestus-plugin-loader")
set(SRC_DIR "src")

if (HEPHAESTUS_SHARED_LIBS)
    set(LINKING DYNAMIC)
endif()

set(HEADERS
    ${INCLUDE_DIR}/dllexport.h
    ${INCLUDE_DIR}/plugin.h
    ${INCLUDE_DIR}/plugin_loader.h
)

set(SOURCES
    ${SRC_DIR}/plugin.cpp
    ${SRC_DIR}/plugin_loader.cpp
)

set(DEPS_PUBLIC
    hephaestus-plugin-api
)

set(DEPS_PRIVATE
    boost::boost
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