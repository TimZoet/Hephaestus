find_package(boost COMPONENTS dll REQUIRED)

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_CURRENT_SOURCE_DIR}../../modules/hephaestus-version")
include(hephaestusVersionString)

set(NAME sample)
set(TYPE module)
set(LINKING DYNAMIC)
set(INCLUDE_DIR "include/sample")
set(SRC_DIR "src")


set(HEADERS
    ${INCLUDE_DIR}/dllexport.h
    ${INCLUDE_DIR}/plugin_api.h
)

set(SOURCES
    ${SRC_DIR}/plugin_api.cpp
)

set(DEPS_PUBLIC
)

set(DEPS_PRIVATE
    boost::boost
    hephaestus-plugin-api
)

make_target(
    NAME ${NAME}
    TYPE ${TYPE} ${LINKING}
    VERSION ${HEPHAESTUS_VERSION}
    FOLDER "plugins"
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
