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
include libraries/conditions/CMakeFiles/conditions.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include libraries/conditions/CMakeFiles/conditions.dir/compiler_depend.make

# Include the progress variables for this target.
include libraries/conditions/CMakeFiles/conditions.dir/progress.make

# Include the compile flags for this target's objects.
include libraries/conditions/CMakeFiles/conditions.dir/flags.make

libraries/conditions/CMakeFiles/conditions.dir/conditions.cpp.o: libraries/conditions/CMakeFiles/conditions.dir/flags.make
libraries/conditions/CMakeFiles/conditions.dir/conditions.cpp.o: /Users/maksim/Study/C++/gameTest/libraries/conditions/conditions.cpp
libraries/conditions/CMakeFiles/conditions.dir/conditions.cpp.o: libraries/conditions/CMakeFiles/conditions.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/maksim/Study/C++/gameTest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object libraries/conditions/CMakeFiles/conditions.dir/conditions.cpp.o"
	cd /Users/maksim/Study/C++/gameTest/build/libraries/conditions && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT libraries/conditions/CMakeFiles/conditions.dir/conditions.cpp.o -MF CMakeFiles/conditions.dir/conditions.cpp.o.d -o CMakeFiles/conditions.dir/conditions.cpp.o -c /Users/maksim/Study/C++/gameTest/libraries/conditions/conditions.cpp

libraries/conditions/CMakeFiles/conditions.dir/conditions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/conditions.dir/conditions.cpp.i"
	cd /Users/maksim/Study/C++/gameTest/build/libraries/conditions && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/maksim/Study/C++/gameTest/libraries/conditions/conditions.cpp > CMakeFiles/conditions.dir/conditions.cpp.i

libraries/conditions/CMakeFiles/conditions.dir/conditions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/conditions.dir/conditions.cpp.s"
	cd /Users/maksim/Study/C++/gameTest/build/libraries/conditions && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/maksim/Study/C++/gameTest/libraries/conditions/conditions.cpp -o CMakeFiles/conditions.dir/conditions.cpp.s

# Object files for target conditions
conditions_OBJECTS = \
"CMakeFiles/conditions.dir/conditions.cpp.o"

# External object files for target conditions
conditions_EXTERNAL_OBJECTS =

libraries/conditions/libconditions.a: libraries/conditions/CMakeFiles/conditions.dir/conditions.cpp.o
libraries/conditions/libconditions.a: libraries/conditions/CMakeFiles/conditions.dir/build.make
libraries/conditions/libconditions.a: libraries/conditions/CMakeFiles/conditions.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/maksim/Study/C++/gameTest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libconditions.a"
	cd /Users/maksim/Study/C++/gameTest/build/libraries/conditions && $(CMAKE_COMMAND) -P CMakeFiles/conditions.dir/cmake_clean_target.cmake
	cd /Users/maksim/Study/C++/gameTest/build/libraries/conditions && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/conditions.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libraries/conditions/CMakeFiles/conditions.dir/build: libraries/conditions/libconditions.a
.PHONY : libraries/conditions/CMakeFiles/conditions.dir/build

libraries/conditions/CMakeFiles/conditions.dir/clean:
	cd /Users/maksim/Study/C++/gameTest/build/libraries/conditions && $(CMAKE_COMMAND) -P CMakeFiles/conditions.dir/cmake_clean.cmake
.PHONY : libraries/conditions/CMakeFiles/conditions.dir/clean

libraries/conditions/CMakeFiles/conditions.dir/depend:
	cd /Users/maksim/Study/C++/gameTest/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/maksim/Study/C++/gameTest /Users/maksim/Study/C++/gameTest/libraries/conditions /Users/maksim/Study/C++/gameTest/build /Users/maksim/Study/C++/gameTest/build/libraries/conditions /Users/maksim/Study/C++/gameTest/build/libraries/conditions/CMakeFiles/conditions.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : libraries/conditions/CMakeFiles/conditions.dir/depend

