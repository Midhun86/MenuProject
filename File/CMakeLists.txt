# Directory structure
set(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# Header file
set(HEADER ${INC_DIR}/file.h)

# Source file
set(SOURCE ${SRC_DIR}/file.c)

# Add the library target
add_library(File STATIC ${SOURCE} ${HEADER})

# Set include directories
target_include_directories(File PUBLIC ${INC_DIR})