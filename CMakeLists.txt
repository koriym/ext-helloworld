# Specify the required CMake version
# link https://cmake.org/cmake/help/latest/command/cmake_minimum_required.html
cmake_minimum_required(VERSION 3.8)

# Specify the project name and language used
# link https://cmake.org/cmake/help/latest/command/project.html
project(helloworld C)

# Specify symbols to be defined during compilation
# link https://cmake.org/cmake/help/latest/command/add_compile_definitions.html
add_compile_definitions(HAVE_HELLOWORLD)

# Use the `php-config` command to get PHP's include directory
# link https://cmake.org/cmake/help/latest/command/execute_process.html
execute_process(
        COMMAND php-config --include-dir
        OUTPUT_VARIABLE PHP_SOURCE
)

# Remove the newline at the end of the obtained directory
# link https://cmake.org/cmake/help/latest/command/string.html
string(REGEX REPLACE "\n$" "" PHP_SOURCE "${PHP_SOURCE}")

# Display the source directory being used as a message
# link https://cmake.org/cmake/help/latest/command/message.html
message("Using source directory: ${PHP_SOURCE}")

# Add include directories
# link https://cmake.org/cmake/help/latest/command/include_directories.html
include_directories(${PHP_SOURCE})
include_directories(${PHP_SOURCE}/main)
include_directories(${PHP_SOURCE}/Zend)
include_directories(${PHP_SOURCE}/TSRM)
include_directories(${PROJECT_SOURCE_DIR})

# Add a custom target `configure`
# Execute `phpize` and `./configure`, and make it depend on source files
# link https://cmake.org/cmake/help/latest/command/add_custom_target.html
add_custom_target(configure
        COMMAND phpize && ./configure
        DEPENDS ${SOURCE_FILES}
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})

# Specify the list of source files
# link https://cmake.org/cmake/help/latest/command/set.html
set(SOURCE_FILES php_helloworld.h helloworld.c)

# Create a library from source files (but exclude from ALL build)
# link https://cmake.org/cmake/help/latest/command/add_library.html
add_library(___ EXCLUDE_FROM_ALL ${SOURCE_FILES})

# Set the behavior of CMake's CMP0115 policy. The new policy executes add_executable() or add_library()
# even if source files don't exist, but generates an error if the generated build can't find those files.
# link https://cmake.org/cmake/help/latest/policy/CMP0115.html
cmake_policy(SET CMP0115 NEW)
