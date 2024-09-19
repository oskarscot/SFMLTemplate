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

file(GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/practical_1/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/practical_1/*.h")

add_executable(SFML_TEST ${SOURCES})

set_property(TARGET SFML_TEST PROPERTY CXX_STANDARD 17)

if(PRODUCTION_BUILD)
    target_compile_definitions(SFML_TEST PUBLIC RESOURCES_PATH="./resources/")
    target_compile_definitions(SFML_TEST PUBLIC PRODUCTION_BUILD=1)
else()
    target_compile_definitions(SFML_TEST PUBLIC RESOURCES_PATH="${CMAKE_CURRENT_SOURCE_DIR}/resources/")
    target_compile_definitions(SFML_TEST PUBLIC PRODUCTION_BUILD=0)
endif()

target_link_libraries(SFML_TEST
        sfml-graphics
        sfml-window
        sfml-system
        sfml-audio
        imgui
        ImGui-SFML::ImGui-SFML
)