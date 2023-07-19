cmake_minimum_required(VERSION 3.26.4)

project(MenuProject)

set(CMAKE_C_STANDARD 11)

if(USE_ARM)
# Set ARM cross-compiler and flags
	set(CMAKE_C_COMPILER arm-linux-gnueabi-gcc)
	set(CMAKE_C_FLAGS "-static")
endif()

# Directory structure
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# Source files
file(GLOB SOURCES "${SRC_DIR}/main.c")

# Add the executable target
add_executable(program ${SOURCES})

# Set include directories
target_include_directories(program PRIVATE ${CMAKE_SOURCE_DIR}/Menu)

# Link with Menu library
target_link_libraries(program PRIVATE Menu)

# Include subdirectories
add_subdirectory(Menu)
add_subdirectory(File)
add_subdirectory(Utility)
