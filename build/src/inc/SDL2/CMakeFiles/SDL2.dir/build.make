# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.27.7/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.27.7/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/maksim/Study/C++/gameTest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/maksim/Study/C++/gameTest/build

# Include any dependencies generated for this target.
include src/inc/SDL2/CMakeFiles/SDL2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/inc/SDL2/CMakeFiles/SDL2.dir/compiler_depend.make

# Include the progress variables for this target.
include src/inc/SDL2/CMakeFiles/SDL2.dir/progress.make

# Include the compile flags for this target's objects.
include src/inc/SDL2/CMakeFiles/SDL2.dir/flags.make

# Object files for target SDL2
SDL2_OBJECTS =

# External object files for target SDL2
SDL2_EXTERNAL_OBJECTS =

src/inc/SDL2/libSDL2.a: src/inc/SDL2/CMakeFiles/SDL2.dir/build.make
src/inc/SDL2/libSDL2.a: src/inc/SDL2/CMakeFiles/SDL2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/maksim/Study/C++/gameTest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Linking CXX static library libSDL2.a"
	cd /Users/maksim/Study/C++/gameTest/build/src/inc/SDL2 && $(CMAKE_COMMAND) -P CMakeFiles/SDL2.dir/cmake_clean_target.cmake
	cd /Users/maksim/Study/C++/gameTest/build/src/inc/SDL2 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SDL2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/inc/SDL2/CMakeFiles/SDL2.dir/build: src/inc/SDL2/libSDL2.a
.PHONY : src/inc/SDL2/CMakeFiles/SDL2.dir/build

src/inc/SDL2/CMakeFiles/SDL2.dir/clean:
	cd /Users/maksim/Study/C++/gameTest/build/src/inc/SDL2 && $(CMAKE_COMMAND) -P CMakeFiles/SDL2.dir/cmake_clean.cmake
.PHONY : src/inc/SDL2/CMakeFiles/SDL2.dir/clean

src/inc/SDL2/CMakeFiles/SDL2.dir/depend:
	cd /Users/maksim/Study/C++/gameTest/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/maksim/Study/C++/gameTest /Users/maksim/Study/C++/gameTest/src/inc/SDL2 /Users/maksim/Study/C++/gameTest/build /Users/maksim/Study/C++/gameTest/build/src/inc/SDL2 /Users/maksim/Study/C++/gameTest/build/src/inc/SDL2/CMakeFiles/SDL2.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/inc/SDL2/CMakeFiles/SDL2.dir/depend

