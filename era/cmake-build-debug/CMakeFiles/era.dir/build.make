# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /snap/clion/44/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/44/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ildar/CLionProjects/era

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ildar/CLionProjects/era/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/era.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/era.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/era.dir/flags.make

CMakeFiles/era.dir/main.cpp.o: CMakeFiles/era.dir/flags.make
CMakeFiles/era.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ildar/CLionProjects/era/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/era.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/era.dir/main.cpp.o -c /home/ildar/CLionProjects/era/main.cpp

CMakeFiles/era.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/era.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ildar/CLionProjects/era/main.cpp > CMakeFiles/era.dir/main.cpp.i

CMakeFiles/era.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/era.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ildar/CLionProjects/era/main.cpp -o CMakeFiles/era.dir/main.cpp.s

# Object files for target era
era_OBJECTS = \
"CMakeFiles/era.dir/main.cpp.o"

# External object files for target era
era_EXTERNAL_OBJECTS =

era: CMakeFiles/era.dir/main.cpp.o
era: CMakeFiles/era.dir/build.make
era: CMakeFiles/era.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ildar/CLionProjects/era/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable era"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/era.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/era.dir/build: era

.PHONY : CMakeFiles/era.dir/build

CMakeFiles/era.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/era.dir/cmake_clean.cmake
.PHONY : CMakeFiles/era.dir/clean

CMakeFiles/era.dir/depend:
	cd /home/ildar/CLionProjects/era/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ildar/CLionProjects/era /home/ildar/CLionProjects/era /home/ildar/CLionProjects/era/cmake-build-debug /home/ildar/CLionProjects/era/cmake-build-debug /home/ildar/CLionProjects/era/cmake-build-debug/CMakeFiles/era.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/era.dir/depend

