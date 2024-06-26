cmake_minimum_required(VERSION 3.21)
project(pacman LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to 'Debug' as none was specified...")
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build." FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  message(STATUS "Setting CXX Flags for Debug build...")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
  message(STATUS "Setting the CXX Flags for Release build...")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -DNDEBUG")
endif()

file(GLOB_RECURSE SUBDIRECTORIES LIST_DIRECTORIES true "${CMAKE_SOURCE_DIR}/src/*")

# uncomment this guy if you've got resources you need to add -- like game sprites or something
# file(COPY res DESTINATION ${CMAKE_BINARY_DIR})

message(STATUS "Subdirectories found:")
foreach(SUBDIR ${SUBDIRECTORIES})
    if(IS_DIRECTORY ${SUBDIR})
        message(STATUS "  Adding: ${SUBDIR}")
        add_subdirectory(${SUBDIR})
    endif()
endforeach()

add_executable(app src/main.cpp ${SOURCE_FILES})

# having linker errors?  undefined references to things?  make sure
# the appropriate folder's named library from its CMakeLists.txt file
# is appended here
# TODO: can we auto-detect these...?
target_link_libraries(
    app
    # extra things like sfml go here if you were going to use them
)

install(TARGETS app)