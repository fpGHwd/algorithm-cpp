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
CMAKE_COMMAND = /opt/clion/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/suzumiya/CLionProjects/beauty-in-code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/suzumiya/CLionProjects/beauty-in-code/cmake-build-debug

# Include any dependencies generated for this target.
include src/leetcode/CMakeFiles/p235.dir/depend.make

# Include the progress variables for this target.
include src/leetcode/CMakeFiles/p235.dir/progress.make

# Include the compile flags for this target's objects.
include src/leetcode/CMakeFiles/p235.dir/flags.make

src/leetcode/CMakeFiles/p235.dir/p235.cpp.o: src/leetcode/CMakeFiles/p235.dir/flags.make
src/leetcode/CMakeFiles/p235.dir/p235.cpp.o: ../src/leetcode/p235.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/suzumiya/CLionProjects/beauty-in-code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/leetcode/CMakeFiles/p235.dir/p235.cpp.o"
	cd /home/suzumiya/CLionProjects/beauty-in-code/cmake-build-debug/src/leetcode && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/p235.dir/p235.cpp.o -c /home/suzumiya/CLionProjects/beauty-in-code/src/leetcode/p235.cpp

src/leetcode/CMakeFiles/p235.dir/p235.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/p235.dir/p235.cpp.i"
	cd /home/suzumiya/CLionProjects/beauty-in-code/cmake-build-debug/src/leetcode && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/suzumiya/CLionProjects/beauty-in-code/src/leetcode/p235.cpp > CMakeFiles/p235.dir/p235.cpp.i

src/leetcode/CMakeFiles/p235.dir/p235.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/p235.dir/p235.cpp.s"
	cd /home/suzumiya/CLionProjects/beauty-in-code/cmake-build-debug/src/leetcode && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/suzumiya/CLionProjects/beauty-in-code/src/leetcode/p235.cpp -o CMakeFiles/p235.dir/p235.cpp.s

# Object files for target p235
p235_OBJECTS = \
"CMakeFiles/p235.dir/p235.cpp.o"

# External object files for target p235
p235_EXTERNAL_OBJECTS =

bin/p235: src/leetcode/CMakeFiles/p235.dir/p235.cpp.o
bin/p235: src/leetcode/CMakeFiles/p235.dir/build.make
bin/p235: src/leetcode/CMakeFiles/p235.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/suzumiya/CLionProjects/beauty-in-code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/p235"
	cd /home/suzumiya/CLionProjects/beauty-in-code/cmake-build-debug/src/leetcode && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/p235.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/leetcode/CMakeFiles/p235.dir/build: bin/p235

.PHONY : src/leetcode/CMakeFiles/p235.dir/build

src/leetcode/CMakeFiles/p235.dir/clean:
	cd /home/suzumiya/CLionProjects/beauty-in-code/cmake-build-debug/src/leetcode && $(CMAKE_COMMAND) -P CMakeFiles/p235.dir/cmake_clean.cmake
.PHONY : src/leetcode/CMakeFiles/p235.dir/clean

src/leetcode/CMakeFiles/p235.dir/depend:
	cd /home/suzumiya/CLionProjects/beauty-in-code/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/suzumiya/CLionProjects/beauty-in-code /home/suzumiya/CLionProjects/beauty-in-code/src/leetcode /home/suzumiya/CLionProjects/beauty-in-code/cmake-build-debug /home/suzumiya/CLionProjects/beauty-in-code/cmake-build-debug/src/leetcode /home/suzumiya/CLionProjects/beauty-in-code/cmake-build-debug/src/leetcode/CMakeFiles/p235.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/leetcode/CMakeFiles/p235.dir/depend

