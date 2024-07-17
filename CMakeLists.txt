cmake_minimum_required(VERSION 3.28)
project(sfml_test)

set(CMAKE_CXX_STANDARD 23)
set(OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY})

set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build SFML as static libraries" FORCE)

set(IMGUI_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib/imgui-docking/imgui")
set(IMGUI_INCLUDE_DIR "${IMGUI_DIR}")
set(IMGUI_SFML_FIND_SFML OFF)
add_subdirectory("lib/sfml")
add_subdirectory("lib/imgui-sfml")
add_subdirectory("lib/imgui-docking")

file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable("${CMAKE_PROJECT_NAME}")

set_property(TARGET "${CMAKE_PROJECT_NAME}" PROPERTY CXX_STANDARD 17)

if(PRODUCTION_BUILD)
    target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC RESOURCES_PATH="./resources/")
    target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC PRODUCTION_BUILD=1)
else()
    target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC RESOURCES_PATH="${CMAKE_CURRENT_SOURCE_DIR}/resources/")
    target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC PRODUCTION_BUILD=0)
endif()

target_sources("${CMAKE_PROJECT_NAME}" PRIVATE ${MY_SOURCES})

target_link_libraries("${CMAKE_PROJECT_NAME}"
        sfml-graphics
        sfml-window
        sfml-system
        sfml-audio
        imgui
        ImGui-SFML::ImGui-SFML
)