include(hephaestusVersionString)

set(NAME hephaestus-version)
set(TYPE module)
set(INCLUDE_DIR "include/hephaestus-version")
set(SRC_DIR "src")

set(HEADERS
    ${INCLUDE_DIR}/dllexport.h
    ${INCLUDE_DIR}/version.h
)

set(SOURCES
    ${SRC_DIR}/version.cpp
)

set(DEPS_PUBLIC
)

set(DEPS_PRIVATE
)

make_target(
    NAME ${NAME}
    TYPE ${TYPE} DYNAMIC
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