# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/suzumiya/CLionProjects/beauty-in-code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/suzumiya/CLionProjects/beauty-in-code

# Include any dependencies generated for this target.
include tests/CMakeFiles/test_netease2017.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/test_netease2017.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/test_netease2017.dir/flags.make

tests/CMakeFiles/test_netease2017.dir/test_netease2017.cpp.o: tests/CMakeFiles/test_netease2017.dir/flags.make
tests/CMakeFiles/test_netease2017.dir/test_netease2017.cpp.o: tests/test_netease2017.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/suzumiya/CLionProjects/beauty-in-code/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/test_netease2017.dir/test_netease2017.cpp.o"
	cd /home/suzumiya/CLionProjects/beauty-in-code/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_netease2017.dir/test_netease2017.cpp.o -c /home/suzumiya/CLionProjects/beauty-in-code/tests/test_netease2017.cpp

tests/CMakeFiles/test_netease2017.dir/test_netease2017.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_netease2017.dir/test_netease2017.cpp.i"
	cd /home/suzumiya/CLionProjects/beauty-in-code/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/suzumiya/CLionProjects/beauty-in-code/tests/test_netease2017.cpp > CMakeFiles/test_netease2017.dir/test_netease2017.cpp.i

tests/CMakeFiles/test_netease2017.dir/test_netease2017.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_netease2017.dir/test_netease2017.cpp.s"
	cd /home/suzumiya/CLionProjects/beauty-in-code/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/suzumiya/CLionProjects/beauty-in-code/tests/test_netease2017.cpp -o CMakeFiles/test_netease2017.dir/test_netease2017.cpp.s

# Object files for target test_netease2017
test_netease2017_OBJECTS = \
"CMakeFiles/test_netease2017.dir/test_netease2017.cpp.o"

# External object files for target test_netease2017
test_netease2017_EXTERNAL_OBJECTS =

bin/test_netease2017: tests/CMakeFiles/test_netease2017.dir/test_netease2017.cpp.o
bin/test_netease2017: tests/CMakeFiles/test_netease2017.dir/build.make
bin/test_netease2017: tests/CMakeFiles/test_netease2017.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/suzumiya/CLionProjects/beauty-in-code/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/test_netease2017"
	cd /home/suzumiya/CLionProjects/beauty-in-code/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_netease2017.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/test_netease2017.dir/build: bin/test_netease2017

.PHONY : tests/CMakeFiles/test_netease2017.dir/build

tests/CMakeFiles/test_netease2017.dir/clean:
	cd /home/suzumiya/CLionProjects/beauty-in-code/tests && $(CMAKE_COMMAND) -P CMakeFiles/test_netease2017.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/test_netease2017.dir/clean

tests/CMakeFiles/test_netease2017.dir/depend:
	cd /home/suzumiya/CLionProjects/beauty-in-code && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/suzumiya/CLionProjects/beauty-in-code /home/suzumiya/CLionProjects/beauty-in-code/tests /home/suzumiya/CLionProjects/beauty-in-code /home/suzumiya/CLionProjects/beauty-in-code/tests /home/suzumiya/CLionProjects/beauty-in-code/tests/CMakeFiles/test_netease2017.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/test_netease2017.dir/depend
