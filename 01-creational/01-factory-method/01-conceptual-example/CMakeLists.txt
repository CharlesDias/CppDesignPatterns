cmake_minimum_required(VERSION 3.21)

project(factory_method_conceptual_example
   DESCRIPTION "This example illustrates the structure of the Factory Method design pattern."
   VERSION 1.0
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)          # Define explicitly to use of the standard C++20 declared in the previous line
set(CMAKE_CXX_EXTENSIONS OFF)                # Disabling vendor-specific extensions

# This is necessary for Sonarlint tools
# If enabled, generates a compile_commands.json file containing the exact compiler calls for all 
# translation units of the project in machine-readable form.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(LIB_NAME factory_method)
set(APP_NAME app)

add_subdirectory(lib)
add_subdirectory(app)