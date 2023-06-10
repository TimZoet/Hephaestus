find_package(boost COMPONENTS dll REQUIRED)

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_CURRENT_SOURCE_DIR}/../hephaestus-version")
include(hephaestusVersionString)

set(NAME hephaestus-plugin-api)
set(TYPE module)
set(LINKING DYNAMIC)
set(INCLUDE_DIR "include/hephaestus-plugin-api")
set(SRC_DIR "src")

set(HEADERS
    ${INCLUDE_DIR}/dllexport.h
    ${INCLUDE_DIR}/plugin_api.h
    ${INCLUDE_DIR}/plugin_info.h
)

set(SOURCES
    ${SRC_DIR}/plugin_api.cpp
)

set(DEPS_PUBLIC
    boost::boost
)

set(DEPS_PRIVATE
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
