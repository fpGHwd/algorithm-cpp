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
include src/CMakeFiles/netease2017_01.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/netease2017_01.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/netease2017_01.dir/flags.make

src/CMakeFiles/netease2017_01.dir/netease/p2017_01.cpp.o: src/CMakeFiles/netease2017_01.dir/flags.make
src/CMakeFiles/netease2017_01.dir/netease/p2017_01.cpp.o: ../src/netease/p2017_01.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/suzumiya/CLionProjects/beauty-in-code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/netease2017_01.dir/netease/p2017_01.cpp.o"
	cd /home/suzumiya/CLionProjects/beauty-in-code/cmake-build-debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/netease2017_01.dir/netease/p2017_01.cpp.o -c /home/suzumiya/CLionProjects/beauty-in-code/src/netease/p2017_01.cpp

src/CMakeFiles/netease2017_01.dir/netease/p2017_01.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/netease2017_01.dir/netease/p2017_01.cpp.i"
	cd /home/suzumiya/CLionProjects/beauty-in-code/cmake-build-debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/suzumiya/CLionProjects/beauty-in-code/src/netease/p2017_01.cpp > CMakeFiles/netease2017_01.dir/netease/p2017_01.cpp.i

src/CMakeFiles/netease2017_01.dir/netease/p2017_01.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/netease2017_01.dir/netease/p2017_01.cpp.s"
	cd /home/suzumiya/CLionProjects/beauty-in-code/cmake-build-debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/suzumiya/CLionProjects/beauty-in-code/src/netease/p2017_01.cpp -o CMakeFiles/netease2017_01.dir/netease/p2017_01.cpp.s

# Object files for target netease2017_01
netease2017_01_OBJECTS = \
"CMakeFiles/netease2017_01.dir/netease/p2017_01.cpp.o"

# External object files for target netease2017_01
netease2017_01_EXTERNAL_OBJECTS =

lib/libnetease2017_01.so: src/CMakeFiles/netease2017_01.dir/netease/p2017_01.cpp.o
lib/libnetease2017_01.so: src/CMakeFiles/netease2017_01.dir/build.make
lib/libnetease2017_01.so: src/CMakeFiles/netease2017_01.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/suzumiya/CLionProjects/beauty-in-code/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library ../lib/libnetease2017_01.so"
	cd /home/suzumiya/CLionProjects/beauty-in-code/cmake-build-debug/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/netease2017_01.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/netease2017_01.dir/build: lib/libnetease2017_01.so

.PHONY : src/CMakeFiles/netease2017_01.dir/build

src/CMakeFiles/netease2017_01.dir/clean:
	cd /home/suzumiya/CLionProjects/beauty-in-code/cmake-build-debug/src && $(CMAKE_COMMAND) -P CMakeFiles/netease2017_01.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/netease2017_01.dir/clean

src/CMakeFiles/netease2017_01.dir/depend:
	cd /home/suzumiya/CLionProjects/beauty-in-code/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/suzumiya/CLionProjects/beauty-in-code /home/suzumiya/CLionProjects/beauty-in-code/src /home/suzumiya/CLionProjects/beauty-in-code/cmake-build-debug /home/suzumiya/CLionProjects/beauty-in-code/cmake-build-debug/src /home/suzumiya/CLionProjects/beauty-in-code/cmake-build-debug/src/CMakeFiles/netease2017_01.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/netease2017_01.dir/depend

