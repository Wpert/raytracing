# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/vpert/gitproj/raytracing/basic_scene

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vpert/gitproj/raytracing/basic_scene

# Include any dependencies generated for this target.
include CMakeFiles/bscene.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/bscene.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/bscene.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bscene.dir/flags.make

CMakeFiles/bscene.dir/main.cpp.o: CMakeFiles/bscene.dir/flags.make
CMakeFiles/bscene.dir/main.cpp.o: main.cpp
CMakeFiles/bscene.dir/main.cpp.o: CMakeFiles/bscene.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/vpert/gitproj/raytracing/basic_scene/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/bscene.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/bscene.dir/main.cpp.o -MF CMakeFiles/bscene.dir/main.cpp.o.d -o CMakeFiles/bscene.dir/main.cpp.o -c /home/vpert/gitproj/raytracing/basic_scene/main.cpp

CMakeFiles/bscene.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/bscene.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vpert/gitproj/raytracing/basic_scene/main.cpp > CMakeFiles/bscene.dir/main.cpp.i

CMakeFiles/bscene.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/bscene.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vpert/gitproj/raytracing/basic_scene/main.cpp -o CMakeFiles/bscene.dir/main.cpp.s

# Object files for target bscene
bscene_OBJECTS = \
"CMakeFiles/bscene.dir/main.cpp.o"

# External object files for target bscene
bscene_EXTERNAL_OBJECTS =

bscene: CMakeFiles/bscene.dir/main.cpp.o
bscene: CMakeFiles/bscene.dir/build.make
bscene: CMakeFiles/bscene.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/vpert/gitproj/raytracing/basic_scene/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bscene"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bscene.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bscene.dir/build: bscene
.PHONY : CMakeFiles/bscene.dir/build

CMakeFiles/bscene.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bscene.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bscene.dir/clean

CMakeFiles/bscene.dir/depend:
	cd /home/vpert/gitproj/raytracing/basic_scene && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vpert/gitproj/raytracing/basic_scene /home/vpert/gitproj/raytracing/basic_scene /home/vpert/gitproj/raytracing/basic_scene /home/vpert/gitproj/raytracing/basic_scene /home/vpert/gitproj/raytracing/basic_scene/CMakeFiles/bscene.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/bscene.dir/depend
