cmake_minimum_required(VERSION 3.10)

project(SFMLCraft
    LANGUAGES CXX
    VERSION 0.0.1
)

set(CMAKE_CXX_STANDARD 17)

# Avoid some VS and XCode specific behaviour with binary folders, so the
# assets symlink works file, also on windows you need permissions, be it by
# a admin cmd or by changing windows to developer mode (which allows symlink
# creation without admin privs)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY                "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG          "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE        "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY                "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG          "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE        "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELWITHDEBINFO "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY                ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG          "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE        "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELWITHDEBINFO "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
file(MAKE_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

# define especific compiler options
if (MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
  string(REPLACE "INCREMENTAL:YES" "INCREMENTAL:NO" 
         replacementFlags ${CMAKE_EXE_LINKER_FLAGS_DEBUG}) 
  set(CMAKE_EXE_LINKER_FLAGS_DEBUG "/INCREMENTAL:NO ${replacementFlags}")
  string(REPLACE "INCREMENTAL:YES" "INCREMENTAL:NO" 
         replacementFlags ${CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO}) 
  set(CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO "/INCREMENTAL:NO ${replacementFlags}")

  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
  add_definitions(-D_SCL_SECURE_NO_WARNINGS)
  add_definitions(-D_WINDOWS_SOURCE)
endif()

# Include and setup external dependencies
set(BUILD_SHARED_LIBS ON)
add_definitions(-D_CRT_SECURE_NO_WARNINGS)
add_subdirectory(third_party/SFML EXCLUDE_FROM_ALL)
add_subdirectory(third_party/glm EXCLUDE_FROM_ALL)
add_subdirectory(third_party/glew-cmake EXCLUDE_FROM_ALL)

# Declare main executable
# file(GLOB_RECURSE CXX_SOURCES src/*.cpp)
add_executable(SFMLCraft
    States/StatePlaying.cpp
    Application.cpp
    Context.cpp
    Shaders/ShaderLoader.cpp
    Shaders/Shader.cpp
    Shaders/BasicShader.cpp
    Texture/BasicTexture.cpp
    Util/FileUtil.cpp
    Texture/BasicTexture.cpp
    Renderer/RenderMaster.cpp 
    Renderer/QuadRenderer.cpp
    Camera.cpp
    Math.cpp
    Model.cpp 
    Main.cpp)

# Link the external dependencies to the game
target_link_libraries(SFMLCraft
    PRIVATE 
        sfml-graphics
        sfml-window
        sfml-system
        libglew_static
        glm
)

# Set the out dir of the binary so it can access the assets by a symlink
add_custom_command(
    TARGET SFMLCraft PRE_BUILD COMMAND
    ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_SOURCE_DIR}/Assets ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Assets
)
# Set the out dir of the binary so it can access the assets by a symlink
add_custom_command(
    TARGET SFMLCraft PRE_BUILD COMMAND
    ${CMAKE_COMMAND} -E create_symlink
    ${CMAKE_SOURCE_DIR}/Shaders ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Shaders
)
