cmake_minimum_required(VERSION 3.15)
project(password_checker LANGUAGES C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Warnings
add_compile_options(-Wall -Wextra)

# Debug/Release flags
set(CMAKE_C_FLAGS_DEBUG "-g")
set(CMAKE_C_FLAGS_RELEASE "-O3")

# ============================================
# Fetch Unity Test Framework
# ============================================
include(FetchContent)

FetchContent_Declare(
    unity
    GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git
    GIT_TAG v2.6.0
)
FetchContent_MakeAvailable(unity)

# ============================================
# Build Main Library
# ============================================
add_library(pwcheck_lib STATIC
    src/analyzer.c
    src/generator.c
    src/validator.c
    src/ui.c
)

# Include the headers
target_include_directories(pwcheck_lib PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Link math library
target_link_libraries(pwcheck_lib PRIVATE m)

# ============================================
# Build Main Program
# ============================================
add_executable(password_checker src/main.c)
target_link_libraries(password_checker PRIVATE pwcheck_lib)

# ============================================
# Build Tests
# ============================================
add_executable(test_analyzer tests/test_analyzer.c)
target_include_directories(test_analyzer PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(test_analyzer PRIVATE pwcheck_lib unity m)

add_executable(test_generator tests/test_generator.c)
target_include_directories(test_generator PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(test_generator PRIVATE pwcheck_lib unity m)

# ============================================
# Enable CTest Integration
# ============================================
enable_testing()

add_test(NAME AnalyzerTests COMMAND test_analyzer)
add_test(NAME GeneratorTests COMMAND test_generator)

# ============================================
# Custom targets for convenience
# ============================================
add_custom_target(run_tests
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS test_analyzer test_generator
    COMMENT "Running all tests..."
)

add_custom_target(run_analyzer_tests
    COMMAND test_analyzer
    DEPENDS test_analyzer
    COMMENT "Running analyzer tests..."
)

add_custom_target(run_generator_tests
    COMMAND test_generator
    DEPENDS test_generator
    COMMENT "Running generator tests..."
)
