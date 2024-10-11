cmake_minimum_required(VERSION 3.23.0)

project(
  ProjectTemplate
  VERSION 0.1.0
  LANGUAGES CXX C
  DESCRIPTION "C++/CMake project template"
  HOMEPAGE_URL "https://www.github.com/oclero"
)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_MACOSX_RPATH 1)
# set(CMAKE_INSTALL_RPATH "@loader_path/../Frameworks")

find_package(Qt6 REQUIRED COMPONENTS
  Core
  Widgets
)

qt_standard_project_setup()

add_subdirectory(sources/app)
add_subdirectory(sources/lib)
