find_package(alexandria REQUIRED)

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_CURRENT_SOURCE_DIR}/../hephaestus-version")
include(hephaestusVersionString)

set(NAME hephaestus-settings)
set(TYPE module)
set(LINKING)
set(INCLUDE_DIR "include/hephaestus-settings")
set(SRC_DIR "src")

if (HEPHAESTUS_SHARED_LIBS)
    set(LINKING DYNAMIC)
endif()

set(HEADERS
    ${INCLUDE_DIR}/dllexport.h
    ${INCLUDE_DIR}/settings.h
)

set(SOURCES
    ${SRC_DIR}/settings.cpp
)

set(DEPS_PUBLIC
)

set(DEPS_PRIVATE
    alexandria::alexandria
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