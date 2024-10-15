set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}/application)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin-int/${CMAKE_BUILD_TYPE}/application)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}/application)

set(IMGUI_DIR "${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui-docking/imgui")
set(IMGUI_INCLUDE_DIR "${IMGUI_DIR}")
set(IMGUI_SFML_FIND_SFML OFF)
add_subdirectory("vendor/sfml")
add_subdirectory("vendor/yaml")

file(GLOB_RECURSE PROJECT_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h")
file(GLOB_RECURSE PROJECT_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_library(engine SHARED ${PROJECT_HEADERS} ${PROJECT_SOURCES})
set_target_properties(engine PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(engine PUBLIC
        ${CMAKE_SOURCE_DIR}/engine/src
)

target_link_libraries(engine PUBLIC
        sfml-graphics
        sfml-window
        sfml-system
        sfml-audio
        yaml-cpp::yaml-cpp
)

if(WIN32)
    target_compile_definitions(engine PUBLIC SFT_WINDOWS SFT_BUILD_DLL)
    set(SFT_PLATFORM "Windows")
elseif(APPLE)
    target_compile_definitions(engine PUBLIC SFT_MACOS SFT_BUILD_DLL)
    set(SFT_PLATFORM "macOS")
elseif(UNIX)
    target_compile_definitions(engine PUBLIC SFT_LINUX SFT_BUILD_DLL)
    set(SFT_PLATFORM "Linux")
else()
    message(FATAL_ERROR "Unsupported platform!")
endif()


add_custom_command(TARGET engine POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/application/resources ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}/application/resources
)

add_custom_command(TARGET engine POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:engine> ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/../application
)

get_target_property(SFT_DEFINITIONS engine COMPILE_DEFINITIONS)
