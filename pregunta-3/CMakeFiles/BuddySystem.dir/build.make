# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_SOURCE_DIR = /mnt/c/Users/Jeamh/CLionProjects/Examen1/pregunta-3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/Jeamh/CLionProjects/Examen1/pregunta-3

# Include any dependencies generated for this target.
include CMakeFiles/BuddySystem.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/BuddySystem.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/BuddySystem.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BuddySystem.dir/flags.make

CMakeFiles/BuddySystem.dir/src/BuddySystem.cpp.o: CMakeFiles/BuddySystem.dir/flags.make
CMakeFiles/BuddySystem.dir/src/BuddySystem.cpp.o: src/BuddySystem.cpp
CMakeFiles/BuddySystem.dir/src/BuddySystem.cpp.o: CMakeFiles/BuddySystem.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Jeamh/CLionProjects/Examen1/pregunta-3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BuddySystem.dir/src/BuddySystem.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/BuddySystem.dir/src/BuddySystem.cpp.o -MF CMakeFiles/BuddySystem.dir/src/BuddySystem.cpp.o.d -o CMakeFiles/BuddySystem.dir/src/BuddySystem.cpp.o -c /mnt/c/Users/Jeamh/CLionProjects/Examen1/pregunta-3/src/BuddySystem.cpp

CMakeFiles/BuddySystem.dir/src/BuddySystem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BuddySystem.dir/src/BuddySystem.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Jeamh/CLionProjects/Examen1/pregunta-3/src/BuddySystem.cpp > CMakeFiles/BuddySystem.dir/src/BuddySystem.cpp.i

CMakeFiles/BuddySystem.dir/src/BuddySystem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BuddySystem.dir/src/BuddySystem.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Jeamh/CLionProjects/Examen1/pregunta-3/src/BuddySystem.cpp -o CMakeFiles/BuddySystem.dir/src/BuddySystem.cpp.s

CMakeFiles/BuddySystem.dir/src/main.cpp.o: CMakeFiles/BuddySystem.dir/flags.make
CMakeFiles/BuddySystem.dir/src/main.cpp.o: src/main.cpp
CMakeFiles/BuddySystem.dir/src/main.cpp.o: CMakeFiles/BuddySystem.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Jeamh/CLionProjects/Examen1/pregunta-3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/BuddySystem.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/BuddySystem.dir/src/main.cpp.o -MF CMakeFiles/BuddySystem.dir/src/main.cpp.o.d -o CMakeFiles/BuddySystem.dir/src/main.cpp.o -c /mnt/c/Users/Jeamh/CLionProjects/Examen1/pregunta-3/src/main.cpp

CMakeFiles/BuddySystem.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BuddySystem.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Jeamh/CLionProjects/Examen1/pregunta-3/src/main.cpp > CMakeFiles/BuddySystem.dir/src/main.cpp.i

CMakeFiles/BuddySystem.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BuddySystem.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Jeamh/CLionProjects/Examen1/pregunta-3/src/main.cpp -o CMakeFiles/BuddySystem.dir/src/main.cpp.s

# Object files for target BuddySystem
BuddySystem_OBJECTS = \
"CMakeFiles/BuddySystem.dir/src/BuddySystem.cpp.o" \
"CMakeFiles/BuddySystem.dir/src/main.cpp.o"

# External object files for target BuddySystem
BuddySystem_EXTERNAL_OBJECTS =

BuddySystem: CMakeFiles/BuddySystem.dir/src/BuddySystem.cpp.o
BuddySystem: CMakeFiles/BuddySystem.dir/src/main.cpp.o
BuddySystem: CMakeFiles/BuddySystem.dir/build.make
BuddySystem: CMakeFiles/BuddySystem.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/Jeamh/CLionProjects/Examen1/pregunta-3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable BuddySystem"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BuddySystem.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BuddySystem.dir/build: BuddySystem
.PHONY : CMakeFiles/BuddySystem.dir/build

CMakeFiles/BuddySystem.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BuddySystem.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BuddySystem.dir/clean

CMakeFiles/BuddySystem.dir/depend:
	cd /mnt/c/Users/Jeamh/CLionProjects/Examen1/pregunta-3 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/Jeamh/CLionProjects/Examen1/pregunta-3 /mnt/c/Users/Jeamh/CLionProjects/Examen1/pregunta-3 /mnt/c/Users/Jeamh/CLionProjects/Examen1/pregunta-3 /mnt/c/Users/Jeamh/CLionProjects/Examen1/pregunta-3 /mnt/c/Users/Jeamh/CLionProjects/Examen1/pregunta-3/CMakeFiles/BuddySystem.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BuddySystem.dir/depend

