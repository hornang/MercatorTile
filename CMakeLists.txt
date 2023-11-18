cmake_minimum_required(VERSION 3.11)

project(mercatortile)

set (CMAKE_CXX_STANDARD 11)

# create the library
add_library(mercatortile src/MercatorTile.cpp)

include(GenerateExportHeader)
generate_export_header(mercatortile)

target_include_directories(mercatortile
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
        $<INSTALL_INTERFACE:include>
)

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
    "${CMAKE_CURRENT_BINARY_DIR}/MercatorTileConfig.cmake"
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/mercatortile
)

install(
    FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/include/mercatortile/MercatorTile.h
        ${CMAKE_CURRENT_BINARY_DIR}/mercatortile_export.h
    DESTINATION
        ${CMAKE_INSTALL_INCLUDEDIR}/mercatortile
)

install(TARGETS mercatortile
    EXPORT MercatorTileTargets
)

install(
    EXPORT MercatorTileTargets
    FILE MercatorTileTargets.cmake
    NAMESPACE MercatorTile::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/mercatortile
)

install(
    FILES
        "${CMAKE_CURRENT_BINARY_DIR}/MercatorTileConfig.cmake"
    DESTINATION
        ${CMAKE_INSTALL_LIBDIR}/cmake/mercatortile
)

option(BUILD_EXAMPLE "Build executable demonstrating basic usage" ON)

if(BUILD_EXAMPLE)
    add_subdirectory(examples)
endif()
