# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /cygdrive/c/Users/Денис/AppData/Local/JetBrains/CLion2021.2/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/Денис/AppData/Local/JetBrains/CLion2021.2/cygwin_cmake/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/d/GitClone/1-sem-itmo-algo-tasks/2lab/taskD

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/d/GitClone/1-sem-itmo-algo-tasks/2lab/taskD/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/taskD.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/taskD.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/taskD.dir/flags.make

CMakeFiles/taskD.dir/main.cpp.o: CMakeFiles/taskD.dir/flags.make
CMakeFiles/taskD.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/d/GitClone/1-sem-itmo-algo-tasks/2lab/taskD/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/taskD.dir/main.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/taskD.dir/main.cpp.o -c /cygdrive/d/GitClone/1-sem-itmo-algo-tasks/2lab/taskD/main.cpp

CMakeFiles/taskD.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/taskD.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/d/GitClone/1-sem-itmo-algo-tasks/2lab/taskD/main.cpp > CMakeFiles/taskD.dir/main.cpp.i

CMakeFiles/taskD.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/taskD.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/d/GitClone/1-sem-itmo-algo-tasks/2lab/taskD/main.cpp -o CMakeFiles/taskD.dir/main.cpp.s

# Object files for target taskD
taskD_OBJECTS = \
"CMakeFiles/taskD.dir/main.cpp.o"

# External object files for target taskD
taskD_EXTERNAL_OBJECTS =

taskD.exe: CMakeFiles/taskD.dir/main.cpp.o
taskD.exe: CMakeFiles/taskD.dir/build.make
taskD.exe: CMakeFiles/taskD.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/d/GitClone/1-sem-itmo-algo-tasks/2lab/taskD/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable taskD.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/taskD.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/taskD.dir/build: taskD.exe
.PHONY : CMakeFiles/taskD.dir/build

CMakeFiles/taskD.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/taskD.dir/cmake_clean.cmake
.PHONY : CMakeFiles/taskD.dir/clean

CMakeFiles/taskD.dir/depend:
	cd /cygdrive/d/GitClone/1-sem-itmo-algo-tasks/2lab/taskD/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/d/GitClone/1-sem-itmo-algo-tasks/2lab/taskD /cygdrive/d/GitClone/1-sem-itmo-algo-tasks/2lab/taskD /cygdrive/d/GitClone/1-sem-itmo-algo-tasks/2lab/taskD/cmake-build-debug /cygdrive/d/GitClone/1-sem-itmo-algo-tasks/2lab/taskD/cmake-build-debug /cygdrive/d/GitClone/1-sem-itmo-algo-tasks/2lab/taskD/cmake-build-debug/CMakeFiles/taskD.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/taskD.dir/depend

