cmake_minimum_required(VERSION 3.24)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_OSX_ARCHITECTURES "x86_64")

project(oko-vision)

# Qt setup ---

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(NOT DEFINED ENV{QT6_DIR})
  message(FATAL_ERROR "QT5 was not found")
endif()

message(STATUS "Using Qt5: \"$ENV{QT5_DIR}\"")

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH}$ENV{QT5_DIR})

find_package(Qt5 REQUIRED COMPONENTS Widgets)

# ------------

add_executable(${PROJECT_NAME}
  Resources/app.qrc
  SourceFiles/main.cpp
  SourceFiles/main_window.h
  SourceFiles/main_window.cpp
  SourceFiles/main_window.ui
)

target_include_directories(${PROJECT_NAME} PRIVATE SourceFiles)

target_link_libraries(
  ${PROJECT_NAME}
  Qt5::Widgets
)
