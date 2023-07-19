# Directory structure
set(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# Header file
set(HEADER ${INC_DIR}/menu.h)

# Source file
set(SOURCE ${SRC_DIR}/menu.c)

# Add the library target
add_library(Menu STATIC ${SOURCE} ${HEADER})

# Set include directories
target_include_directories(Menu PUBLIC ${INC_DIR})

# Link with File and Utility libraries
target_link_libraries(Menu PUBLIC File Utility)