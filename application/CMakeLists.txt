set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}/application)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin-int/${CMAKE_BUILD_TYPE}/application)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}/application)

set(IMGUI_DIR "${CMAKE_CURRENT_SOURCE_DIR}/vendor/imgui-docking/imgui")
set(IMGUI_INCLUDE_DIR "${IMGUI_DIR}")
set(IMGUI_SFML_FIND_SFML OFF)
add_subdirectory("vendor/imgui-sfml")
add_subdirectory("vendor/imgui-docking")

file(GLOB_RECURSE PROJECT_HEADERS "src/*.h")
file(GLOB_RECURSE PROJECT_SOURCES "src/*.cpp")
add_executable(application ${PROJECT_HEADERS} ${PROJECT_SOURCES})

target_include_directories(application PRIVATE
        ${CMAKE_SOURCE_DIR}/engine/src
)

target_link_libraries(application PRIVATE
        engine
        imgui
        ImGui-SFML::ImGui-SFML
)