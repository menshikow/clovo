# CMake generated Testfile for 
# Source directory: /home/menschikov/dev/passcheck
# Build directory: /home/menschikov/dev/passcheck/build-debug
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(AnalyzerTests "/home/menschikov/dev/passcheck/build-debug/test_analyzer")
set_tests_properties(AnalyzerTests PROPERTIES  _BACKTRACE_TRIPLES "/home/menschikov/dev/passcheck/CMakeLists.txt;64;add_test;/home/menschikov/dev/passcheck/CMakeLists.txt;0;")
add_test(GeneratorTests "/home/menschikov/dev/passcheck/build-debug/test_generator")
set_tests_properties(GeneratorTests PROPERTIES  _BACKTRACE_TRIPLES "/home/menschikov/dev/passcheck/CMakeLists.txt;65;add_test;/home/menschikov/dev/passcheck/CMakeLists.txt;0;")
subdirs("_deps/unity-build")
