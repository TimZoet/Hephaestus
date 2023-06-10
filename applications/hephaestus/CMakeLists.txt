set(WIN_LIBS)
if (MSVC)
    find_library(win_ole32 ole32)
    find_library(win_uuid uuid)
    set(WIN_LIBS ${win_ole32} ${win_uuid})
endif()

set(NAME hephaestus)
set(TYPE application)
set(INCLUDE_DIR "include/hephaestus")
set(SRC_DIR "src")

set(HEADERS
    ${INCLUDE_DIR}/application.h
    ${INCLUDE_DIR}/generators.h
    ${INCLUDE_DIR}/window.h

    ${INCLUDE_DIR}/data_sources/bool_data_source.h
    ${INCLUDE_DIR}/data_sources/index_data_source.h
    ${INCLUDE_DIR}/data_sources/string_list_data_source.h

    ${INCLUDE_DIR}/models/global_model.h
    ${INCLUDE_DIR}/models/indexed_string_list_model.h

    ${INCLUDE_DIR}/panels/simple_panel.h
)

set(SOURCES
    ${SRC_DIR}/application.cpp
    ${SRC_DIR}/generators.cpp
    ${SRC_DIR}/main.cpp
    ${SRC_DIR}/window.cpp

    ${SRC_DIR}/data_sources/bool_data_source.cpp
    ${SRC_DIR}/data_sources/index_data_source.cpp
    ${SRC_DIR}/data_sources/string_list_data_source.cpp

    ${SRC_DIR}/models/global_model.cpp
    ${SRC_DIR}/models/indexed_string_list_model.cpp

    ${SRC_DIR}/panels/simple_panel.cpp
)

set(DEPS_PUBLIC
    hephaestus-gui
    hephaestus-plugin-loader
    hephaestus-settings
    hephaestus-version
    ${WIN_LIBS}
)

make_target(
    TYPE ${TYPE}
    NAME ${NAME}
    HEADERS "${HEADERS}"
    SOURCES "${SOURCES}"
    DEPS_PUBLIC "${DEPS_PUBLIC}"
)

install_target(
    NAME ${NAME}
    TYPE ${TYPE}
    VERSION 1.0.0 # TODO: Get version from elsewhere.
)

target_compile_definitions(${NAME}
    PRIVATE
        RESOURCES_DIR="${PROJECT_SOURCE_DIR}/applications/hephaestus/resources"
)
