cmake_minimum_required(VERSION 3.8)

project("Dear ImGui Template")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory("dependencies/glfw-3.3.5")
add_subdirectory("dependencies/glm")

add_library(glad "dependencies/glad/glad.h" "dependencies/glad/glad.c")

find_package(OpenGL REQUIRED)

set(IMGUI_HEADERS	"src/ImGui/imgui.h"
					"src/ImGui/imconfig.h"
					"src/ImGui/imgui_impl_glfw.h"
					"src/ImGui/imgui_impl_opengl3.h"
					"src/ImGui/imgui_impl_opengl3_loader.h"
					"src/ImGui/imgui_internal.h"
					"src/ImGui/imstb_rectpack.h"
					"src/ImGui/imstb_textedit.h"
					"src/ImGui/imstb_truetype.h")
set(IMGUI_SOURCES	"src/ImGui/imgui.cpp"
					"src/ImGui/imgui_demo.cpp"
					"src/ImGui/imgui_draw.cpp"
					"src/ImGui/imgui_impl_glfw.cpp"
					"src/ImGui/imgui_impl_opengl3.cpp"
					"src/ImGui/imgui_tables.cpp"
					"src/ImGui/imgui_widgets.cpp")

set(HEADER_FILES ${IMGUI_HEADERS})
set(SOURCE_FILES ${IMGUI_SOURCES} "src/Main.cpp")

add_executable (Dear-ImGui-App ${HEADER_FILES} ${SOURCE_FILES})

# TODO: Add tests and install targets if needed.
target_link_libraries(Dear-ImGui-App glfw)
target_link_libraries(Dear-ImGui-App glm)
target_link_libraries(Dear-ImGui-App glad)

target_link_libraries(Dear-ImGui-App OpenGL::GL)

target_include_directories(Dear-ImGui-App PUBLIC "dependencies/glad")