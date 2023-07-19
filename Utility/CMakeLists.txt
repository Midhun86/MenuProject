# Directory structure
set(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# Header file
set(HEADER ${INC_DIR}/utility.h)

# Source file
set(SOURCE ${SRC_DIR}/utility.c)

# Add the library target
add_library(Utility STATIC ${SOURCE} ${HEADER})

# Set include directories
target_include_directories(Utility PUBLIC ${INC_DIR})