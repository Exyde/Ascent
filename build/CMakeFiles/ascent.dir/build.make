# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sly/workspace/dive/Ascent

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sly/workspace/dive/Ascent/build

# Include any dependencies generated for this target.
include CMakeFiles/ascent.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ascent.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ascent.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ascent.dir/flags.make

CMakeFiles/ascent.dir/main.cpp.o: CMakeFiles/ascent.dir/flags.make
CMakeFiles/ascent.dir/main.cpp.o: ../main.cpp
CMakeFiles/ascent.dir/main.cpp.o: CMakeFiles/ascent.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sly/workspace/dive/Ascent/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ascent.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ascent.dir/main.cpp.o -MF CMakeFiles/ascent.dir/main.cpp.o.d -o CMakeFiles/ascent.dir/main.cpp.o -c /home/sly/workspace/dive/Ascent/main.cpp

CMakeFiles/ascent.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ascent.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sly/workspace/dive/Ascent/main.cpp > CMakeFiles/ascent.dir/main.cpp.i

CMakeFiles/ascent.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ascent.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sly/workspace/dive/Ascent/main.cpp -o CMakeFiles/ascent.dir/main.cpp.s

# Object files for target ascent
ascent_OBJECTS = \
"CMakeFiles/ascent.dir/main.cpp.o"

# External object files for target ascent
ascent_EXTERNAL_OBJECTS =

ascent: CMakeFiles/ascent.dir/main.cpp.o
ascent: CMakeFiles/ascent.dir/build.make
ascent: /usr/lib/x86_64-linux-gnu/libGL.so.1
ascent: CMakeFiles/ascent.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sly/workspace/dive/Ascent/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ascent"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ascent.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ascent.dir/build: ascent
.PHONY : CMakeFiles/ascent.dir/build

CMakeFiles/ascent.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ascent.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ascent.dir/clean

CMakeFiles/ascent.dir/depend:
	cd /home/sly/workspace/dive/Ascent/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sly/workspace/dive/Ascent /home/sly/workspace/dive/Ascent /home/sly/workspace/dive/Ascent/build /home/sly/workspace/dive/Ascent/build /home/sly/workspace/dive/Ascent/build/CMakeFiles/ascent.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ascent.dir/depend
